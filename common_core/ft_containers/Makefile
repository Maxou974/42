NAME = a.out

SRCS = main.cpp test/alphabet.cpp ${TESTFCT}
TESTFCT = test/stack.cpp test/vector.cpp test/map.cpp test/pair.cpp #test/type_traits.cpp

OBJS = ${SRCS:.cpp=.o}

CC = c++
FLAGS = -g3 -Wall  -Wextra -Werror -Wshadow -std=c++98


.cpp.o:
	${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

all: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

${NAME}: all

clean:
	@rm -rf ${OBJS}

fclean: clean
	@rm -rf ${NAME}

re: fclean all

stdd:
	@sed -i 's/ft::/std::/g' ${TESTFCT}
	@make re
	@make clean

ftt:
	@sed -i 's/std::/ft::/g' ${TESTFCT}
	@make re
	@make clean

test: 
	@./.script.sh

mand_test:
	@echo "STL"
	@c++ ${FLAGS} -D STL=1 mand_main.cpp
	@/usr/bin/time --format="time: %es  CPU: %P" ./a.out $(seed)
	@echo "FT"
	@c++ ${FLAGS} -D STL=0 mand_main.cpp
	@/usr/bin/time --format="time: %es  CPU: %P" ./a.out $(seed)
	@rm a.out


.PHONY: all fclean clean re stdd ftt test time mand_test