
NAME = mutantStack

SRCS = main.cpp Span.cpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
		${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
		${CC} ${FLAGS} -o ${NAME} ${OBJS}

clean:
	rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re: fclean all

.PHONY:	all re fclean clean