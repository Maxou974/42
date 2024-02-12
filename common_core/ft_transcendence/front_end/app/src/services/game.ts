import axios from "axios";
import { BACKEND_URL } from "src/pages/global/env";

const API_URL = BACKEND_URL + "/game";

const joinMatchmaking = async (userId: number, gameMode: string) => {
  return await axios
    .post(`${API_URL}/matchmaking/${userId}`, { gameMode })
    .then((res: any) => res.data);
};

const leaveMatchmaking = async (userId: number) => {
  return await axios
    .get(`${API_URL}/matchmaking/leave/${userId}`)
    .then((res: any) => res.data);
};

const getUserInvites = async (userId: number) => {
  return await axios
    .get(`${API_URL}/invites/${userId}`)
    .then((res: any) => res.data);
};

const deleteUserInvites = async (userId: number) => {
  return await axios
    .post(`${API_URL}/deleteInvites/${userId}`)
    .then((res: any) => res.data);
};

const sendInvite = async (
  userId: number,
  invitedUserId: number,
  gameMode: string
) => {
  return await axios
    .post(`${API_URL}/sendInvite/${userId}`, {
      invitedUserId,
      gameMode,
    })
    .then((res: any) => res.data);
};

const declineInvite = async (userId: number, declinedUserId: number) => {
  return await axios
    .post(`${API_URL}/declineInvite/${userId}`, {
      declinedUserId,
    })
    .then((res: any) => res.data);
};

const acceptInvite = async (userId: number, acceptedUserId: number) => {
  return await axios
    .post(`${API_URL}/acceptInvite/${userId}`, {
      acceptedUserId,
    })
    .then((res: any) => res.data);
};

const getMatchHistory = async (userId: number) => {
  return await axios
    .get(`${API_URL}/matchHistory/${userId}`)
    .then((res: any) => res.data);
};

const getUserCurrentGame = async (userId: number) => {
  return await axios
	.get(`${API_URL}/runningGame/${userId}`)
	.then((res: any) => res.data);
}

const gameService = {
  joinMatchmaking,
  leaveMatchmaking,
  getUserInvites,
  deleteUserInvites,
  sendInvite,
  declineInvite,
  acceptInvite,
  getMatchHistory,
  getUserCurrentGame,
};

export default gameService;
