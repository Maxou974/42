# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 19:09:21 by mabriel           #+#    #+#              #
#    Updated: 2022/10/12 03:13:33 by mabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= sed

SRC		= main.cpp 
OBJS	= ${SRC:.cpp=.o}

CC		= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98

.cpp.o:
		${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS}
		${CC} ${FLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re