# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 18:18:00 by mabriel           #+#    #+#              #
#    Updated: 2022/10/20 11:40:08 by mabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ = ${SRC:.cpp=.o}

NAME = Fixed

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