# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 18:11:24 by mabriel           #+#    #+#              #
#    Updated: 2022/10/04 23:15:53 by mabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone

SRC		= megaphone.cpp
OBJS	= $(SRC:.cpp=.o)

CC		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98

.cpp.o:
		${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

$(NAME): ${OBJS}
		${CC} ${FLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re