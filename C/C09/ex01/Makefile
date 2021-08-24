# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nobody <marvin@42.fr>                     +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 22:31:41 by mabriel           #+#    #+#              #
#    Updated: 2021/08/24 20:17:17 by mabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCFOLD		=	./srcs/
HEADFOLD	=	./includes/
SRCS		=	${SRCFOLD}ft_putchar.c	\
				${SRCFOLD}ft_putstr.c	\
				${SRCFOLD}ft_strcmp.c	\
				${SRCFOLD}ft_strlen.c	\
				${SRCFOLD}ft_swap.c
HEADER		=	${HEADFOLD}ft.h
OBJS		=	${SRCS:.c=.o}
NAME		=	libft.a
CC			=	gcc	-Wall -Wextra -Werror

.c.o:
				${CC} -c $< -o ${<:.c=.o} -I ${HEADFOLD}

${NAME}:		${OBJS}
				ar rc ${NAME} ${OBJS}
		
all: 			${NAME}

clean:
				rm -f ${OBJS}

fclean:			clean
				rm -f ${NAME}

re:				fclean all

.PHONY: 		all clean fclean re
