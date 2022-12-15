NAME = a.out

SRCS = main.cpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
FLAGS = -g -Wall  -Wextra -Werror -std=c++98

.cpp.o:
	${CC} ${FLAGS} -c $< -o ${OBJS}

all: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

${NAME}: all

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all
	valgrind ./${NAME}

std:
	./sed main.cpp "ft::" "std::"
	rm main.cpp
	mv main.cpp.replace main.cpp

ft:
	./sed main.cpp "std::" "ft::"
	rm main.cpp
	mv main.cpp.replace main.cpp

reft: ft re

restd: std re
	 

.PHONY: all fclean clean re 