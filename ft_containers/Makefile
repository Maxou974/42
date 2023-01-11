NAME = a.out

SRCS = main.cpp test/alphabet.cpp ${TESTFCT}
TESTFCT = test/stack.cpp test/vector.cpp test/map.cpp test/pair.cpp #test/type_traits.cpp

TESTTIME = test/vector_time.cpp test/time.cpp test/map_time.cpp 

TESTTIMEOBJS = ${TESTTIME:.cpp=.o}
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
	@sed -i 's/ft::/std::/g' ${TESTTIME}
	@make re
	@make clean

ftt:
	@sed -i 's/std::/ft::/g' ${TESTFCT}
	@sed -i 's/std::/ft::/g' ${TESTTIME}
	@make re
	@make clean

test: 
	@./.script.sh

time: 
	@sed -i 's/ft::/std::/g' ${TESTTIME}
	@${CC} ${TESTTIME} -o timestd
	@/usr/bin/time --format="std:: time: %es  CPU: %P" ./timestd
	@sed -i 's/std::/ft::/g' ${TESTTIME}
	@${CC} ${TESTTIME} -o timeft
	@/usr/bin/time --format=" ft:: time: %es  CPU: %P" ./timeft
	@rm timeft timestd

.PHONY: all fclean clean re stdd ftt test time