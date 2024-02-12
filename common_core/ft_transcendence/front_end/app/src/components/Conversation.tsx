import Avatar from "@mui/material/Avatar";
import List from "@mui/material/List";
import { Badge, ListItem } from "@mui/material";
import axios, { AxiosError } from "axios";
import React, { useEffect, useState } from "react";
import { useNavigate } from "react-router";
import { ConversationProps } from "src/pages/chat/types/ConversationProps.types";
import { BACKEND_URL } from "src/pages/global/env";
import TextInputWithEnterCallback from "../pages/global/TextInput";
import { userId } from "../pages/global/userId";
import { useSessionContext } from "src/context/SessionContext";
import PrivateTextArea from "./private-message.text-area";

import SelectedConversationInterations from "src/pages/chat/components/SelectedConversationInteractions";
import { useErrorContext } from "src/context/ErrorContext";
import { errorHandler } from "src/context/errorHandler";

const getColorFromStatus = (status: string): string => {
  if (status === "Online") return "green";
  else if (status === "Offline") return "grey";
  else if (status === "In game") return "red";
  return "blue";
};

const FriendAvatar = ({ conv, friendId, friendUsername }: any) => {
  return (
    <Badge
      overlap="circular"
      variant="dot"
      anchorOrigin={{ vertical: "bottom", horizontal: "right" }}
      sx={{
        "& .MuiBadge-badge": {
          backgroundColor: getColorFromStatus(conv.userstatus),
        },
      }}
    >
      <Avatar
        className={"avatar " + (conv.convIsUnRead ? "unread" : "")}
        alt={friendUsername}
        src={BACKEND_URL + "/user/image/" + friendId}
        sx={{ width: 60, height: 60 }}
      />
    </Badge>
  );
};

const Conversation = ({ onClick, conv, chatId, setConvs }: any) => {
  const id = conv.conversation.id;
  const friendId =
    userId === conv.conversation.memberOneId
      ? conv.conversation.memberTwoId
      : conv.conversation.memberOneId;
  const friendUsername = conv.conversation.friendUsername;

  return (
    <div
      className={chatId === conv.conversation.id ? "friend-selected" : "friend"}
    >
      <ListItem key={id} onClick={onClick}>
        {conv.userstatus ? (
          <FriendAvatar
            conv={conv}
            friendId={friendId}
            friendUsername={friendUsername}
          />
        ) : (
          <Avatar
            className={"avatar " + (conv.convIsUnRead ? "unread" : "")}
            alt={friendUsername}
            src={BACKEND_URL + "/user/image/" + friendId}
            sx={{ width: 60, height: 60 }}
          />
        )}
        <div className="private-message-name">{friendUsername}</div>
      </ListItem>
      {chatId === conv.conversation.id ? (
        <div>
          <SelectedConversationInterations data={conv} setConvs={setConvs} />
        </div>
      ) : (
        false
      )}
    </div>
  );
};

const Conversations = ({ chatId }: { chatId: number | undefined }) => {
  const [convs, setConvs] = useState<ConversationProps[]>([]);
  const [showTextArea, setshowTextArea] = useState(false);
  const [currentChat, setCurrentChat] = useState<ConversationProps>();
  const [createConvBool, setCreateConvBool] = useState(false);
  const navigate = useNavigate();
  const errorContext = useErrorContext();
  const session = useSessionContext();

  useEffect(() => {
    axios
      .get(BACKEND_URL + "/privatemessage/conversations", {
        withCredentials: true,
      })
      .then((res: any): any => {
        if (chatId) {
          const up = res.data.map((m: any) =>
            m.conversation.id === chatId ? { ...m, convIsUnRead: false } : m
          );
          setConvs(up);
          const cur = up.filter((m: any) => {
            return m.conversation.id === chatId;
          })[0];
          if (!cur) navigate("/404");
          setCurrentChat(cur);
          setshowTextArea(true);
        } else setConvs(res.data);
      })
      .catch((error: Error | AxiosError) => {
        errorContext.newError?.(errorHandler(error));
      });
    // eslint-disable-next-line
  }, [chatId, navigate]);

  useEffect(() => {
    const listenNewConv = (conv: ConversationProps) => {
      setConvs((prev: ConversationProps[]) => [...prev, conv]);
    };

    session.socket?.on("new-conv", listenNewConv);

    return () => {
      session.socket?.off("new-conv", listenNewConv);
    };
  }, [session.socket]);

  const handleclick = (e: ConversationProps) => {
    convUpdateUnReadStatus(e.conversation.id, false);
    navigate("/chat/" + e.conversation.id);
  };

  const createConv = () => {
    setCreateConvBool(!createConvBool);
  };

  const hideInput = () => {
    setCreateConvBool(false);
  };

  const createConvCallBack = (inputValue: any) => {
    axios
      .get(BACKEND_URL + "/user/idbyname/" + inputValue, {
        withCredentials: true,
      })
      .then((response: any) => {
        axios
          .post(
            BACKEND_URL + "/privatemessage/conversations/" + response.data,
            null,
            { withCredentials: true }
          )
          .then((res: any) => {
            const exist = convs.some(
              (conv: ConversationProps) =>
                conv.conversation.id === res.data.conversation.id
            );
            if (!exist)
              setConvs((prev: ConversationProps[]) => [...prev, res.data]);
          })
          .catch((error: Error | AxiosError) =>
            errorContext.newError?.(errorHandler(error))
          );
      })
      .catch((error: Error | AxiosError) =>
        errorContext.newError?.(errorHandler(error))
      );
  };

  const convUpdateUnReadStatus = (
    conversationId: number,
    readStatus: boolean
  ) => {
    const updated = convs.map((conv: ConversationProps) =>
      conv.conversation.id === conversationId
        ? { ...conv, convIsUnRead: readStatus }
        : conv
    );

    setConvs(updated);
  };

  useEffect(() => {
    const listenNewMessage = (message: any) => {
      if (
        !currentChat ||
        currentChat.conversation.id !== message.conversationId
      ) {
        const updated = convs.map((conv: ConversationProps) =>
          conv.conversation.id === message.conversationId
            ? { ...conv, convIsUnRead: true }
            : conv
        );

        setConvs(updated);
      }
    };

    const listenNewStatus = (status: any) => {
      const updatedConvs = convs.map((conv: ConversationProps) =>
        conv.conversation.memberOneId === status.userId ||
        conv.conversation.memberTwoId === status.userId
          ? { ...conv, userstatus: status.userstatus }
          : conv
      );
      setConvs(updatedConvs);
    };

    session.socket?.on("new-message", listenNewMessage);
    session.socket?.on("user-status", listenNewStatus);

    return () => {
      session.socket?.off("new-message", listenNewMessage);
      session.socket?.off("user-status", listenNewStatus);
    };
  }, [session.socket, currentChat, convs]);

  return (
    <>
      <div className="channel-top-bar">
        {showTextArea && currentChat && (
          <>
            <img
              className="channel-top-bar-img"
              alt={currentChat.conversation.friendUsername + " avatar"}
              src={
                BACKEND_URL + "/user/image/" + currentChat.conversation.friendId
              }
            />
            <div className="private-message-name">
              {currentChat.conversation.friendUsername}
            </div>
          </>
        )}
        <div className="left-but">
          <button className="btn btn-light" onClick={() => navigate("/")}>
            home
          </button>{" "}
        </div>
      </div>
      <div className="channel-member-bar">
        <div onClick={createConv} className="privMsg">
          Private message +
          {createConvBool && (
            <TextInputWithEnterCallback
              id="owebno"
              onEnterPress={createConvCallBack}
              hideInput={hideInput}
            />
          )}
        </div>
        <List>
          {convs ? (
            <div>
              {Object.keys(convs).map((i) => (
                <Conversation
                  key={convs[parseInt(i)].conversation.id}
                  onClick={() => handleclick(convs[parseInt(i)])}
                  conv={convs[parseInt(i)]}
                  chatId={chatId}
                  setConvs={setCurrentChat}
                />
              ))}
            </div>
          ) : null}
        </List>
      </div>
      {showTextArea && currentChat && (
        <PrivateTextArea currentChat={currentChat} userId={userId} />
      )}
    </>
  );
};

export default Conversations;
