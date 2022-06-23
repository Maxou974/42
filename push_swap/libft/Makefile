# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabriel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 13:03:51 by mabriel           #+#    #+#              #
#    Updated: 2022/04/11 17:08:58 by mabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS        = 	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putnbr_fd.c ft_atoll.c \
				ft_putendl_fd.c ft_free_split.c ft_strcmp.c \
				get_next_line.c get_next_line_utils.c ft_quote_split.c

BONUS	= ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c \
		  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

NAME 	= libft.a

OBJS 	= ${SRCS:.c=.o}
BON		= ${BONUS:.c=.o}

CC		= cc
RM		= rm -f

CFLAGS 	= -fPIE -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

bonus:	${BON} ${NAME}
		ar rcs ${NAME} ${BON}

clean:
		${RM} ${OBJS} ${BON}

fclean:	clean
		${RM} ${NAME}

re: fclean all

.PHONY : all bonus clean fclean re .c.o

