# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 16:18:44 by mabriel           #+#    #+#              #
#    Updated: 2022/10/31 20:09:54 by mabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Materia

SRC = main.cpp Cure.cpp Ice.cpp AMateria.cpp Character.cpp MateriaSource.cpp
OBJS = ${SRC:.cpp=.o}

FLAGS = -Wall -Wextra -std=c++98

.cpp.o:
		c++ ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}: ${OBJS}
		c++ ${FLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all fclean re clean