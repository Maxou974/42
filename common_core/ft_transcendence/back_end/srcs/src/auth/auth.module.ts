import { Module } from '@nestjs/common';
import { JwtModule, JwtService } from '@nestjs/jwt';
import { ScheduleModule } from '@nestjs/schedule';
import { PrismaModule } from 'src/prisma/prisma.module';
import { AuthController } from './auth.controller';
import { AuthService } from './auth.service';
import { AtStrategy, RtStrategy } from './strategies';
import { TfaStrategy } from './strategies/tfa.strategy';

@Module({  
	imports: [JwtModule.register({}), PrismaModule, ScheduleModule.forRoot()],
	controllers: [AuthController],
	providers: [AuthService, JwtService, AtStrategy, RtStrategy, TfaStrategy],
	exports: [JwtService, AuthService]
})
export class AuthModule {}
