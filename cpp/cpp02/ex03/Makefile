# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 18:18:00 by mabriel           #+#    #+#              #
#    Updated: 2022/10/11 18:21:52 by mabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp
OBJ = ${SRC:.cpp=.o}

NAME = brain

CC= c++
FLAGS = -Wall -Werror -Wextra -std=c++98

.cpp.o:
		${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}: ${OBJ}
		${CC} ${FLAGS} ${OBJ} -o ${NAME}

all: ${NAME}

clean:
		rm -rf ${OBJ}

fclean:	clean
		rm -rf ${NAME}

re: fclean all

.PHONY: re all clean fclean