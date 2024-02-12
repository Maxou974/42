import {
  BadRequestException,
  HttpException,
  HttpStatus,
  Injectable,
  NotFoundException,
  UnauthorizedException,
  UnprocessableEntityException,
} from "@nestjs/common";
import { JwtService } from "@nestjs/jwt";
import { Interval } from "@nestjs/schedule";
import { hash, verify } from "argon2";
import axios from "axios";
import { plainToInstance } from "class-transformer";
import { Response } from "express";
import * as fs from "fs";
import { authenticator } from "otplib";
import { AuthDto } from "src/auth/dto/auth.dto";
import { FtApiUserDto } from "src/auth/dto/ftapi.dto";
import { Tokens } from "src/auth/types";
import { PrismaService } from "src/prisma/prisma.service";
import { URLSearchParams } from "url";

@Injectable()
export class AuthService {
  state_map = new Map<string, Date>();

  constructor(
    private prisma: PrismaService,
    private jwtService: JwtService
  ) {}

  getFtAuthenticationUri(): string {
    const uri = this.buildFtAuthUri();

    return uri;
  }

  async authenticateUser(query: AuthDto, response: Response): Promise<void> {
    const userFtToken: string = await this.getFtApiToken(
      query.code,
      query.state
    );

    const userData: FtApiUserDto = await this.getUserDataFromFtApi(userFtToken);

    let user = await this.prisma.user.findUnique({
      where: {
        id: userData.id,
      },
    });

    if (!user) {
      user = await this.createNewUserInDB(userData);
      await this.getAvatar(userData.id, userData.image["versions"]["small"]);
    }

    if (user.isTwoFAEnable) {
      const tfaToken = await this.getTfaToken(user.id, user.email);

      response.cookie("TfaEnable", "true", {
        httpOnly: false,
        sameSite: "strict",
        maxAge: 7 * 24 * 60 * 60 * 100,
      });
      response.cookie("TfaToken", tfaToken, {
        httpOnly: false,
        sameSite: "strict",
        maxAge: 7 * 24 * 60 * 60 * 100,
      });
    } else {
      const tokens = await this.getTokens(userData.id, userData.email);

      response.cookie("TfaEnable", "false");
      response.cookie("access_token", tokens.access_token, {
        httpOnly: false,
        sameSite: "strict",
        maxAge: 7 * 24 * 60 * 60 * 100,
      });
      response.cookie("refresh_token", tokens.refresh_token, {
        httpOnly: false,
        sameSite: "strict",
        maxAge: 7 * 24 * 60 * 60 * 100,
      });
      response.cookie("userId", userData.id, {
        httpOnly: false,
        sameSite: "strict",
        maxAge: 7 * 24 * 60 * 60 * 100,
      });
    }
    response.redirect(process.env.FRONT_END_URL);
  }

  async verifyTfa(code: string, userId: number) {
    const user = await this.prisma.user.findUnique({
      where: {
        id: userId,
      },
    });

    if (!user.isTwoFAEnable || !user.twoFASecret)
      throw new BadRequestException("TFA is not enabled");

    const bool = authenticator.verify({
      token: code,
      secret: user.twoFASecret,
    });

    if (!bool) throw new UnprocessableEntityException("Wrong code, try again");

    return await this.getTokens(userId, user.email);
  }

  async logout(userId: number) {
    await this.prisma.user.updateMany({
      where: {
        id: userId,
        hashedRt: {
          not: null,
        },
      },
      data: {
        hashedRt: null,
      },
    });
  }

  async refreshTokens(userId: number, rt: string): Promise<Tokens> {
    const user = await this.prisma.user.findUnique({
      where: {
        id: userId,
      },
    });

    if (!user) throw new NotFoundException("No user found");

    if (!user.hashedRt || !(await verify(user.hashedRt, rt)))
      throw new UnauthorizedException("Invalid refresh token");

    const tokens = await this.getTokens(user.id, user.email);

    await this.updateRtHash(user.id, tokens.refresh_token);

    return tokens;
  }

  async getFtApiToken(code: string, state: string): Promise<any> {
    if (!this.state_map.delete(state))
      throw new BadRequestException(
        "Are you trying to hack something ? I see you 👀"
      );

    const authCallbackUri =
      process.env.BACKEND_URL + process.env.AUTH_CALLBACK_URI;

    const user = await axios
      .postForm(process.env.FT_OAUTH_TOKEN_URL, {
        grant_type: "authorization_code",
        client_id: process.env.FT_API_CLIENTID,
        client_secret: process.env.FT_API_SECRET,
        code: code,
        redirect_uri: authCallbackUri,
        state: state,
      })
      .catch((err) => {
        const res = {
          message: "42 Auth API returned an error for token request",
          ...err.response?.data,
        };

        throw new HttpException(res, err.response.status);
      });
    return user.data.access_token;
  }

  async getUserDataFromFtApi(access_token: string): Promise<FtApiUserDto> {
    const res = await axios
      .get("https://api.intra.42.fr/v2/me", {
        headers: {
          Authorization: `Bearer ${access_token}`,
        },
      })
      .catch((error) => {
        if (error.response) {
          const res = {
            message: "42 api returned an error while getting user info",
            ...error.response.data,
          };

          throw new HttpException(res, error.response.status);
        }
        throw new HttpException(
          "Something went wrong when requesting user infos at 42 API",
          HttpStatus.BAD_REQUEST
        );
      });

    const user_data = plainToInstance(FtApiUserDto, res.data, {
      excludeExtraneousValues: true,
    });

    return user_data;
  }

  async getTokens(userId: number, email: string): Promise<Tokens> {
    const userData = {
      sub: userId,
      email: email,
    };

    const [at, rt] = await Promise.all([
      this.jwtService
        .signAsync(userData, {
          secret: process.env.JWT_AT_SECRET,
          expiresIn: "2h",
        })
        .catch((error) => {
          throw new HttpException(error, HttpStatus.INTERNAL_SERVER_ERROR);
        }),
      this.jwtService
        .signAsync(userData, {
          secret: process.env.JWT_RT_SECRET,
          expiresIn: "7d",
        })
        .catch((error) => {
          throw new HttpException(error, HttpStatus.INTERNAL_SERVER_ERROR);
        }),
    ]);

    let payload: string;
    if (at && rt) {
      payload = "logged=true; sameSite=Strict";
    }

    await this.updateRtHash(userId, rt);

    return {
      access_token: at,
      refresh_token: rt,
      payload_cookie: payload,
    };
  }

  async updateRtHash(userId: number, rt: string) {
    const hashed = await this.hashData(rt);

    await this.prisma.user.updateMany({
      where: {
        id: userId,
      },
      data: {
        hashedRt: hashed,
      },
    });
  }

  async getTfaToken(userId: number, email: string) {
    return await this.jwtService
      .signAsync(
        { sub: userId, email },
        {
          secret: process.env.JWT_TFA_SECRET,
          expiresIn: 15 * 60,
        }
      )
      .catch((error) => {
        throw new HttpException(error, HttpStatus.INTERNAL_SERVER_ERROR);
      });
  }

  buildFtAuthUri(): string {
    const state: string = authenticator.generateSecret(20);

    this.state_map.set(state, new Date());

    const authCallbackUri =
      process.env.BACKEND_URL + process.env.AUTH_CALLBACK_URI;
    const paramString = new URLSearchParams("");

    paramString.append("client_id", process.env.FT_API_CLIENTID);
    paramString.append("redirect_uri", authCallbackUri);
    paramString.append("response_type", "code");
    paramString.append("scope", "public");
    paramString.append("state", state);

    const url = process.env.FT_OAUTH_AUTHO_URL + "?" + paramString.toString();

    return url;
  }

  async getAvatar(userId: number, imageUrl: string) {
    const file =
      process.env.AVATAR_DIRECTORY + "/" + userId.toString() + ".jpeg";

    axios({
      method: "get",
      url: imageUrl,
      responseType: "stream",
    })
      .then((response) => {
        const imageStream = response.data.pipe(fs.createWriteStream(file));

        return new Promise((resolve, reject) => {
          imageStream.on("finish", resolve);
          imageStream.on("error", reject);
        });
      })
      .catch((error) => {
        console.error("Error Downloading 42 image:", error.message);
        throw new HttpException(
          "Error Downloading 42 image",
          HttpStatus.INTERNAL_SERVER_ERROR
        );
      });
  }

  async createNewUserInDB(userData: FtApiUserDto) {
    return await this.prisma.user.create({
      data: {
        id: userData.id,
        email: userData.email,
        username: userData.login,
        realname: userData.login,
      },
    });
  }

  async hashData(data: string) {
    return await hash(data);
  }

  @Interval(60000)
  handleInterval() {
    const time = new Date();
    this.state_map.forEach((v, k, map) => {
      if (time.valueOf() - v.valueOf() > 10000) map.delete(k);
    });
  }
}
