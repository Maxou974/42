# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 02:17:23 by mabriel           #+#    #+#              #
#    Updated: 2022/10/11 02:24:19 by mabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Account
SRCS	= Account.cpp tests.cpp
OBJS	= ${SRCS:.cpp=.o}

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98


.cpp.o:
	${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}: ${OBJS}
		${CC} ${FLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all fclean clean re
