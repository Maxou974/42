NAME = a.out

SRCS = main.cpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
FLAGS = -g -Wall  -Wextra -Werror -std=c++98

.cpp.o:
	@${CC} ${FLAGS} -c $< -o ${OBJS}

all: ${OBJS}
	@${CC} ${FLAGS} -o ${NAME} ${OBJS}

${NAME}: all

clean:
	@rm -rf ${OBJS}

fclean: clean
	@rm -rf ${NAME}

re: fclean all

stdd:
	./sed main.cpp "ft::" "std::"
	mv main.cpp.replace main.cpp

ftt:
	./sed main.cpp "std::" "ft::"
	mv main.cpp.replace main.cpp

testre: fclean all
		valgrind ./a.out

test:
	@./script.sh

.PHONY: all fclean clean re std ft