# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 15:47:04 by mabriel           #+#    #+#              #
#    Updated: 2022/03/15 16:46:38 by mabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
SRCS	= array.c help_array.c help_sort.c main.c op.c push_swap.c six_sort.c sort.c clear.c
SRCS_C	= array.c help_array.c checker.c op.c push_swap.c sort.c clear.c help_sort.c 
OBJS	= ${SRCS:.c=.o}
OBJS_C	= ${SRCS_C:.c=.o}
CC	= gcc
FLAGS	= -Wall -Wextra -Werror

%.o : %.c
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	make -C libft
	${CC} ${FLAGS} -o $@ ${OBJS} libft/libft.a

bonus : all ${OBJS_C}
	make -C libft
	${CC} ${FLAGS} -o checker ${OBJS_C} libft/libft.a

all : ${NAME}

clean :
	rm -f ${OBJS} ${OBJS_C}
	make clean -C libft

fclean : clean
	rm -f ${NAME} checker
	make fclean -C libft

re : fclean all

pw : all bonus clean

.PHONY : all pw clean fclean re bonus
