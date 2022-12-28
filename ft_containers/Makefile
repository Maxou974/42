NAME = a.out

SRCS = main.cpp test/vector.cpp test/type_traits.cpp test/alphabet.cpp test/pair.cpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
FLAGS = -g -Wall  -Wextra -Werror -Wshadow #-std=c++98

.cpp.o:
	${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

all: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

${NAME}: all

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

stdd:
	sed -i 's/ft::/std::/g' test/vector.cpp
	sed -i 's/ft::/std::/g' test/type_traits.cpp
	sed -i 's/ft::/std::/g' test/pair.cpp
	make re

ftt:
	@sed -i 's/std::/ft::/g' test/vector.cpp
	@sed -i 's/std::/ft::/g' test/type_traits.cpp
	@sed -i 's/std::/ft::/g' test/pair.cpp
	@make re > /dev/null

test: 
	@./.script.sh

.PHONY: all fclean clean re stdd ftt test