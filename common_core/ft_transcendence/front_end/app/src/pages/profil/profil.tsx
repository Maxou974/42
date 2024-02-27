import React, { useEffect, useState } from "react";
import { useNavigate, useParams } from "react-router-dom";

import Avatar from "@mui/material/Avatar";
import axios, { AxiosError } from "axios";
import { ReadCookie } from "src/components/ReadCookie";
import Menu from "src/components/menu";
import "src/css/profil.css";
import { BACKEND_URL } from "../global/env";

import { useErrorContext } from "src/context/ErrorContext";
import { errorHandler } from "src/context/errorHandler";

import { useSessionContext } from "src/context/SessionContext";
import { userId } from "../global/userId";

import { useGamePopup } from "src/context/GamePopupContext";

import InviteGameModeDialogButton from "src/components/game/GameModeDialog/InviteGameModeDialogButton";
import InteractiveFriendshipButton from "src/components/interactive/InteractiveFriendshipButton";

export interface userProfileDto {
  username: string;
  realname: string;
  photo: string;
  score: number;
  win: number;
  loose: number;
  description: string;
  isFriend: boolean;
}

const defaultUser: userProfileDto = {
  username: "",
  realname: "",
  photo: "",
  score: 0,
  win: 0,
  loose: 0,
  description: "",
  isFriend: false,
};

const Profil: React.FC = () => {
  const [profilInfo, setProfilInfo] = useState<userProfileDto>({
    ...defaultUser,
  });
  const navigate = useNavigate();

  const errorContext = useErrorContext();
  const session = useSessionContext();
  const gameContext = useGamePopup();

  const { id } = useParams();

  useEffect(() => {
    axios
      .get(`${BACKEND_URL}/user/profile/${id}`, { withCredentials: true })
      .then((response: any) => {
        setProfilInfo({
          ...response.data,
          photo: BACKEND_URL + `/user/image/${id}`,
        });
      })
      .catch((err: Error | AxiosError) => {
        errorContext.newError?.(errorHandler(err));
        navigate("/profil/" + userId);
      });
    // eslint-disable-next-line
  }, [id, session.socket]);

  return (
    <div className="content">
      <div className="header-bar">
        <div className="header">
          {id !== ReadCookie("userId") && (
            <>
              <InviteGameModeDialogButton
                user={{
                  id: parseInt(id ?? "0"),
                  username: profilInfo.username,
                  userstatus: null,
                  photo: profilInfo.photo,
                }}
              />
              <InteractiveFriendshipButton
                receiverId={parseInt(id ?? "0")}
                isFriend={profilInfo.isFriend}
                removeFriend={() => {
                  setProfilInfo({ ...profilInfo, isFriend: false });
                }}
              />
            </>
          )}
          {id === ReadCookie("userId") && (
            <button
              className="btn btn-light"
              onClick={() => navigate("/profil/edit-Profil")}
            >
              edit profil
            </button>
          )}
          <button
            className="btn btn-light"
            onClick={() => {
              axios
                .post(
                  BACKEND_URL + "/auth/logout",
                  {},
                  {
                    headers: {
                      Authorization: `Bearer ${ReadCookie("access_token")}`,
                    },
                    withCredentials: true,
                  }
                )
                .then(() => {
                  session.logout?.();
                  gameContext.setIsVisible(false);
                  navigate("/");
                })
                .catch((err: Error | AxiosError) => {
                  errorContext.newError?.(errorHandler(err));
                });
            }}
          >
            Logout
          </button>
          <button className="btn btn-light" onClick={() => navigate("/")}>
            home
          </button>
        </div>
      </div>
      <Menu />
      <div className="profil">
        <center>
          <Avatar
            src={profilInfo.photo + `?key=` + Math.random()}
            style={{
              width: "100px",
              height: "100px",
              borderRadius: "50%",
              objectFit: "cover",
            }}
          />
          <br />
        </center>
        <div className="information">
          <div className="fs-2">
            Nickname : <br />
            <div style={{ paddingLeft: "5%" }}>
              {profilInfo.username} ({profilInfo.realname})<br />
              <br />
            </div>
            <hr />
            <h3>Games statistics:</h3>
            <div style={{ paddingLeft: "5%" }}>
              Win : {profilInfo.win} {"\u00A0"}
              {"\u00A0"} - {"\u00A0"}
              {"\u00A0"} Lose : {profilInfo.loose} <br />
              <br />
              Current ELO : {profilInfo.score} <br />
              <br />
            </div>
            {profilInfo.description ? (
              <>
                <hr />
                About me : <br />
                <div id="helloXSS" style={{ paddingLeft: "5%", wordBreak: "break-all" }}>
                  {/* profilInfo.description */}
                </div>
              </>
            ) : (
              ""
            )}
          </div>
        </div>
      </div>
    </div>
  );
};

export default Profil;
