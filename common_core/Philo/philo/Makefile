# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 03:19:38 by mabriel           #+#    #+#              #
#    Updated: 2022/07/15 20:03:56 by mabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS	= philo.c args.c time.c watch.c init.c action.c check.c ft_strlen.c
OBJS	= ${SRCS:.c=.o}

CC		= gcc
FLAGS	= -Werror -Wextra -Wall -pthread
#FLAGS	= -Werror -Wextra -Wall -pthread -g3 -fsanitize=thread

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${FLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re: fclean all

phi: all clean

.PHONY:	all clean fclean re phi