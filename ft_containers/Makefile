NAME = a.out

SRCS = main.cpp vector.cpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
FLAGS = -g -Wall  -Wextra -Werror -Wshadow -std=c++98

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
	@sed -i 's/ft::/std::/g' ./vector.cpp
	@sed -i 's/ft::/std::/g' ./type_traits.cpp
	@make re > /dev/null

ftt:
	@sed -i 's/std::/ft::/g' ./vector.cpp
	@sed -i 's/std::/ft::/g' ./type_traits.cpp
	@make re > /dev/null

testre: fclean all
		@valgrind ./a.out

test:
	@./script.sh

.PHONY: all fclean clean re stdd ftt