import { Body, Controller, Get, HttpCode, HttpStatus, Param, ParseIntPipe, Post, Res, UploadedFile, UseInterceptors } from '@nestjs/common';
import { FileInterceptor } from '@nestjs/platform-express';
import { Response } from "express";
import { GetCurrentUser } from 'src/common/decorators';
import { ChannelService } from './channel.service';
import { CreateChannelDto } from './dto/CreateChannel.dto';
import { IncomingChannelMessage } from './dto/IncomingChannelMessage.dto';
import { JoinPrivateChannelDto, JoinProtectedChannelDto, JoinPublicChannelDto } from './dto/JoinChannel.dto';
import { ManageChannelRole } from './dto/ManageChannelRole.dto';
import { RestrictChannelMember } from './dto/RestrictChannelMember.dto';

@Controller('channel')
export class ChannelController {

	constructor(private channelService: ChannelService) { }

	@Post('update/:channelId')
	@HttpCode(HttpStatus.OK)
	async UpdateChannel(
		@GetCurrentUser('sub') userId: number,
		@Body() body: CreateChannelDto,
		@Param('channelId', ParseIntPipe) channelId: number
	) {
		await this.channelService.updateChannel(userId, channelId, body)
	}

	@Post('join/public')
	@HttpCode(HttpStatus.OK)
	async JoinPublicChannel(
		@GetCurrentUser('sub') userId: number, 
		@Body() body: JoinPublicChannelDto,
	) {
		await this.channelService.joinPublicChannel(userId, body)
	}
  
	@Post('join/protected')
	@HttpCode(HttpStatus.OK)
	async JoinProtectedChannel(
		@GetCurrentUser('sub') userId: number,
		@Body() body: JoinProtectedChannelDto,
	) {
		await this.channelService.joinProtectedChannel(userId, body)
	}

	@Get('leave/:channelId')
	async LeaveChannel(
		@GetCurrentUser('sub') userId: number,
		@Param('channelId', ParseIntPipe) channelId: number
	) {
		await this.channelService.leaveChannel(userId, channelId)
	}

	@Post()
	@HttpCode(HttpStatus.OK)
	async CreateChannel(
		@GetCurrentUser('sub') userId: number,
		@Body() body: CreateChannelDto) {
		return await this.channelService.createChannel(userId, body)
	}

	@Get()
	async GetAllChannelOfUser(@GetCurrentUser('sub') userId: number) {
		return await this.channelService.getAllChannels(userId)
	}

	@Get('info/:channelId') 
	async GetChannelInfo(
			@GetCurrentUser('sub') userId: number,
			@Param('channelId', ParseIntPipe) channelId: number) {
		return await this.channelService.getChannelInfo(userId, channelId)
	}

	@Get('messages/:channelId')  
	async GetAllChannelMessages(
		@GetCurrentUser('sub') userId: number,
		@Param('channelId', ParseIntPipe) channelId: number) {
		return await this.channelService.getChannelMessages(userId, channelId)
	}

	@Post('messages')
	@HttpCode(HttpStatus.OK)
	async CreateChannelMessage(
		@GetCurrentUser('sub') userId: number,
		@Body() message: IncomingChannelMessage
	) {
		await this.channelService.createNewMessage(userId, message)
	}

	@Post('restrict')
	@HttpCode(HttpStatus.OK)
	async RestrictMember(
		@GetCurrentUser('sub') userId: number,
		@Body() body: RestrictChannelMember
	) {
		await this.channelService.restrictChannelMember(userId, body)
	}

	@Post('unban/:channelId/:channelMemberId')
	@HttpCode(HttpStatus.OK)
	async Unban(
		@GetCurrentUser('sub') userId: number,
		@Param('channelId', ParseIntPipe) channelId: number,
		@Param('channelMemberId', ParseIntPipe) channelMemberId: number
	) {
		await this.channelService.unbanMember(userId, channelId,channelMemberId)
	}

	@Post('manage/role')
	@HttpCode(HttpStatus.OK)
	async ManageChannelAdmin (
		@GetCurrentUser('sub') userId: number,
		@Body() body: ManageChannelRole
	) {
		await this.channelService.manageRole(userId, body)
	}

	@Get('members/:channelId')
	async GetAllChannelMembers(
		@GetCurrentUser('sub') userId: number,
		@Param('channelId', ParseIntPipe) channelId: number) {
		return await this.channelService.getAllChannelMembers(userId, channelId)
	}

	@Get('list')
	async getListOfChannels(
		@GetCurrentUser('sub') userId: number,
	) {
		return await this.channelService.getChannelsList(userId)
	}

	@Post('upload/badge/:channelId')
	@UseInterceptors(FileInterceptor('badge'))
	async uploadAvatar(
		@UploadedFile() file: Express.Multer.File,
		@GetCurrentUser('sub') userId: number,
		@Param('channelId') channelId: number) {
		await this.channelService.uploadBadge(userId, channelId, file)
	}

	@Get('badge/:channelId')
	async getBadge(
		@Res() res: Response,
		@Param('channelId', ParseIntPipe) channelId: number
	) {
		return await this.channelService.getChannelBadge(res, channelId)
	}

}
