
NAME=pipex
BONUS=pipex_bonus

HELP	= $(addprefix lib/, ft_putstr_fd.c ft_strjoin.c ft_split.c ft_quote_split.c ft_strnstr.c ft_free_split.c ft_substr.c ft_strlen.c ft_strcmp.c ft_strncmp.c)
SRCS	= exec_ve.c do_pipex_bonus.c pipex.c error.c
BONSRCS	= exec_ve.c do_pipex_bonus.c pipex_bonus.c lib/get_next_line.c lib/get_next_line_utils.c error.c
OBJS	= ${SRCS:.c=.o} ${HELP:.c=.o}
BONOBJS	=${BONSRCS:.c=.o} ${HELP:.c=.o}
CC	= gcc
FLAGS	= -Wall -Wextra -Werror

%.o : %.c
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	${CC} ${FLAGS} -o $@ ${OBJS}

bonus: ${BONOBJS}
	${CC} ${CFLAGS} -o ${BONUS} ${BONOBJS}

clean: 
	rm -f ${OBJS} ${BONOBJS}

fclean: clean
	rm -f ${NAME} ${BONUS}

re: fclean all

pipe: all clean

.PHONY: all fclean clean re
