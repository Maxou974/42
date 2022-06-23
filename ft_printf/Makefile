# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabriel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 22:47:54 by mabriel           #+#    #+#              #
#    Updated: 2021/12/07 04:13:15 by mabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_ulltoa.c ft_uitoa_base_maj.c ft_printf.c ft_treat_print_c_s.c ft_print_u_x_X_d_p.c
OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make bonus -C ./libft
	cp libft/libft.a ${NAME}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}
	make clean -C ./libft

fclean: clean
	${RM} ${NAME}
	${RM} ./libft/libft.a

re: fclean all

bonus: ${NAME}

ft_printf: all clean
	${RM} ./libft/libft.a

.PHONY : all bonus fclean re clean ft_printf
