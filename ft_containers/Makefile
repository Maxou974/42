NAME = a.out

SRCS = main.cpp test/stack.cpp test/vector.cpp test/map.cpp test/alphabet.cpp test/pair.cpp
TESTFCT = test/stack.cpp test/vector.cpp test/map.cpp test/pair.cpp #test/type_traits.cpp
OBJS = ${SRCS:.cpp=.o}

CC = c++
FLAGS = -g -Wall  -Wextra -Werror -Wshadow -std=c++98

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
	# sed -i 's/ft::/std::/g' test/vector.cpp
	# sed -i 's/ft::/std::/g' test/type_traits.cpp
	# sed -i 's/ft::/std::/g' test/pair.cpp
	# sed -i 's/ft::/std::/g' test/map.cpp
	# sed -i 's/ft::/std::/g' test/stack.cpp
	  sed -i 's/ft::/std::/g' ${TESTFCT}
	
	make re

ftt:
	@sed -i 's/std::/ft::/g' test/vector.cpp
	@sed -i 's/std::/ft::/g' test/type_traits.cpp
	@sed -i 's/std::/ft::/g' test/pair.cpp
	@sed -i 's/std::/ft::/g' test/map.cpp
	@sed -i 's/std::/ft::/g' test/stack.cpp
	@make re

test: 
	@./.script.sh

.PHONY: all fclean clean re stdd ftt test