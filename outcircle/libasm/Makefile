
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_write.s ft_read.s

NAME = libasm.a
TEST = test

OBJS_PATH = objs/
SRCS_PATH = src/

OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.s=.o))


${OBJS_PATH}%.o: ${SRCS_PATH}%.s
		@mkdir -p objs
		nasm -felf64 -o $@ $<

${NAME}: ${OBJS}
		ar -rcs ${NAME} ${OBJS}

all: ${NAME}

clean: 
	rm -rf ${OBJS_PATH}

fclean: clean
	rm -rf ${NAME}
	rm -rf ${TEST}

re: fclean all

test: ${NAME}
	gcc -Wall -Werror -Wextra -no-pie -L . -lasm -o ${TEST} main.c ${NAME}
	./${TEST}

.PHONY: all clean fclean re test