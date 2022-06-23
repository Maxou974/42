# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 00:31:38 by mabriel           #+#    #+#              #
#    Updated: 2022/04/13 18:48:19 by mabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= $(addprefix srcs/, check_arg.c parser.c utils_parser.c main.c \
				free_exit.c img.c moves.c)

BONUS	= $(addprefix bonus/, check_arg_bonus.c parser_bonus.c utils_parser_bonus.c main_bonus.c \
				free_exit_bonus.c img_bonus.c moves_bonus.c)

OBJS	= ${SRCS:.c=.o}

BON_OBJS= ${BONUS:.c=.o}

CC	= gcc
FLAGS	= -Wall -Werror -Wextra
MLX	= -Lmlx -lmlx -lXext -lX11 -lm -lz -L ./mlx

%.o:%.c
	${CC} ${FLAGS} -I/usr/include -Imlx -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	make -C libft
	make -C mlx
	${CC} ${FLAGS} -o ${NAME} ${OBJS} libft/libft.a ${MLX}

bonus:	${BON_OBJS}
	make -C libft
	make -C mlx
	${CC} ${FLAGS} -o ${NAME} ${BON_OBJS} libft/libft.a ${MLX}

clean:
	make clean -C libft
	make clean -C mlx
	rm -rf ${OBJS} ${BON_OBJS}

fclean:	clean
	make fclean -C libft
	rm -rf ${NAME}

re:	fclean all

.PHONY : all clean fclean re %.o
