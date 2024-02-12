import {
  ConnectedSocket,
  MessageBody,
  OnGatewayConnection,
  OnGatewayDisconnect,
  SubscribeMessage,
  WebSocketGateway,
  WebSocketServer,
} from "@nestjs/websockets";
import { Socket, Server } from "socket.io";
import {
  vec2,
  BallInfo,
  defaultBallInfo,
  GameInfo,
  defaultGameInfo,
  UserGameId,
  JoinGameDto,
  INITIAL_VELOCITY,
} from "./game-info.dto";

import { UserStatus } from "src/user/gateway/dto/userStatus.dto";

import { startBallRoutine } from "./game-logic";
import { GameService } from "../game.service";

@WebSocketGateway({ transports: ["websocket"], namespace: "game" })
export class GameGateway implements OnGatewayConnection, OnGatewayDisconnect {
  constructor(private gameService: GameService) {}

  @WebSocketServer()
  private server!: Server;

  private runningGames = new Map<string, GameInfo>();
  private connectedUsers = new Map<string, UserGameId>();

  handleConnection(@ConnectedSocket() client: Socket) {}

  handleDisconnect(@ConnectedSocket() client: Socket) {
    const userGameId = this.connectedUsers.get(client.id);
    if (userGameId === undefined) return;

    this.onGameUnmount([userGameId.gameId, userGameId.userId], client);
  }

  @SubscribeMessage("game:unmount")
  onGameUnmount(
    @MessageBody() data: (string | number)[],
    @ConnectedSocket() client: Socket
  ) {
    const [gameId, userId] = data;

    const currentGame = this.runningGames.get(gameId as string);

    this.connectedUsers.delete(client.id);
    client.disconnect();

    if (currentGame === undefined) return;

    if (userId !== currentGame.player1 && userId !== currentGame.player2)
      return;

    if (currentGame.intervalId !== undefined) {
      clearInterval(currentGame.intervalId);
      currentGame.intervalId = undefined;
    }

    if (currentGame.gameStatus === "FINISHED") {
      this.runningGames.delete(gameId as string);
    } else {
      if (userId === currentGame.player1) {
        currentGame.winnerId = currentGame.player2;
        currentGame.player1Score = -42;
      } else if (userId === currentGame.player2) {
        currentGame.winnerId = currentGame.player1;
        currentGame.player2Score = -42;
      }

      this.gameService.deleteRunningGame(userId);
      this.gameService.createMatchHistoryItem(currentGame);
      this.server
        .to(gameId as string)
        .emit("game:winner", currentGame.winnerId);
      currentGame.gameStatus = "FINISHED";
    }
  }

  @SubscribeMessage("game:join")
  async handleJoinGame(
    @MessageBody() data: JoinGameDto,
    @ConnectedSocket() client: Socket
  ) {
    let [player1Id, player2Id, userId] = [data[0], data[1], data[2]];

    if (data[0] === null || data[1] === null || data[2] === null) {
      client.emit("game:badRequest");
      return;
    }
    if (player1Id < player2Id)
      player1Id = [player2Id, (player2Id = player1Id)][0];

    const gameId = `${player1Id}-${player2Id}`;
    let currentGame = this.runningGames.get(gameId);

    const currentGameExists = currentGame !== undefined;

    if (currentGame === undefined) {
      currentGame = { ...defaultGameInfo };
      this.runningGames.set(gameId, currentGame);
    }

    const invite = await this.gameService.getUsersSharedInvite(
      player1Id,
      player2Id
    );

    if (currentGameExists === false && invite === null) {
      client.emit("game:badRequest");
      this.runningGames.delete(gameId);
      return;
    } else if (currentGameExists === true && invite !== null) {
      currentGame.gamemode = invite.gameMode as
        | "classic"
        | "timed"
        | "speed"
        | "retro";
      if (currentGame.gamemode === "retro") currentGame.maxScore = 11;
      if (currentGame.gamemode === "timed") currentGame.maxScore = 100;
    }

    this.connectedUsers.set(client.id, { userId: userId, gameId: gameId });

    client.join(gameId);

    if (userId === player1Id) {
      currentGame.player1 = userId;
    } else if (userId === player2Id) {
      currentGame.player2 = userId;
    } else {
      client.emit(
        "game:init",
        gameId,
        currentGame.gamemode,
        currentGame.player1,
        currentGame.player2,
        currentGame.player1Score,
        currentGame.player2Score,
        currentGame.dueTime - new Date().getTime()
      );
      return;
    }

    if (
      currentGame.gameStatus === "PREPARING" &&
      currentGame.player1 !== undefined &&
      currentGame.player2 !== undefined
    ) {
      currentGame.gameStatus = "PLAYING";
      this.gameService.deleteUserInvites(currentGame.player1);
      this.gameService.deleteUserInvites(currentGame.player2);
      this.gameService.registerRunningGame({
        player1Id: currentGame.player1,
        player2Id: currentGame.player2,
        gameMode: currentGame.gamemode,
      });
      currentGame.dueTime = new Date().getTime() + 60000;
      this.server
        .to(gameId)
        .emit(
          "game:init",
          gameId,
          currentGame.gamemode,
          currentGame.player1,
          currentGame.player2,
          currentGame.player1Score,
          currentGame.player2Score,
          currentGame.dueTime - new Date().getTime()
        );
      setTimeout(
        () =>
          startBallRoutine(this.gameService, this.server, currentGame, gameId),
        1000
      );
    }
  }

  @SubscribeMessage("game:paddleMove")
  onGamePaddleMove(@MessageBody() data: (number | string)[]) {
    const [paddlePosition, gameId, player] = data;
    const currentGame = this.runningGames.get(gameId as string);

    if (currentGame !== undefined && player === currentGame.player1) {
      currentGame.player1PadY = paddlePosition as number;
    } else if (currentGame !== undefined && player === currentGame.player2) {
      currentGame.player2PadY = paddlePosition as number;
    }

    this.server
      .to(gameId as string)
      .emit("game:newPaddlePosition", paddlePosition, player);
  }
}
