
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_write.s ft_read.s

NAME = libasm.a
TEST = test
OBJS = ${SRCS:.s=.o}

%.o: %.s
		nasm -felf64 -o ${<:.s=.o} $<

${NAME}: ${OBJS}
		ar -rcs ${NAME} ${OBJS}

all: ${NAME}

clean: 
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${TEST}
	rm -rf ${NAME}

re: fclean all

test: ${NAME} clean
	gcc -Wall -Werror -Wextra -no-pie -L . -lasm -o ${TEST} main.c ${NAME}
	./${TEST}

.PHONY: all clean fclean re