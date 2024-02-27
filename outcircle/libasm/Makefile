
SRCS = ft_strlen.asm ft_strcpy.asm ft_strcmp.asm ft_strdup.asm

NAME = libasm.a
TEST = test
OBJS = ${SRCS:.asm=.o}

%.o: %.asm
		nasm -felf64 -o ${<:.asm=.o} $<

${NAME}: ${OBJS}
		ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean: 
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${TEST}
	rm -rf ${NAME}

re: fclean all

test: ${NAME} clean
	gcc -Wall -Werror -Wextra -no-pie -o ${TEST} main.c ${NAME}
	./${TEST}

.PHONY: all clean fclean re