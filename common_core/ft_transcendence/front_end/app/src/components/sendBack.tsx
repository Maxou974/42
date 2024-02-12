import axios from 'axios';
import {ReadCookie} from "./ReadCookie";

const sendBack = async (url: string) => {
  try {
    const response = await axios.get(url);
    return response;
  } catch (error) {
    console.error('Erreur lors de la récupération des données du backend', error);
  }
  return;
};

const sendBackPost = async (url: string) => {
  try {
    const response = await axios.post(url, {}, {headers: {Authorization: `Bearer ${ReadCookie("access_token")}`}, withCredentials: true});
    return response;
  } catch (error) {
    console.error('Erreur lors de la récupération des données du backend', error);
  }
  return;
};

export default sendBack;
export {sendBackPost};