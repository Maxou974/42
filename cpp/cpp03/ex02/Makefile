NAME = ClapTrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FlagTrap.cpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

.cpp.o:
		${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}: ${OBJS}
		${CC} ${FLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: re all clean fclean 