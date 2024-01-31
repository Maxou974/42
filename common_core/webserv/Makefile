CC		= c++
FLAGS	= -std=c++98 -Wall -Wextra -g -Werror

NAME	= webserv

SRCS =	$(wildcard srcs/*.cpp)
SRCS_DIR =	srcs

OBJS	= $(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)
OBJS_DIR= objs

INCLUDES_DIR = includes

$(OBJS_DIR)/%.o: 	$(SRCS_DIR)/%.cpp
			mkdir -p ${OBJS_DIR}
			${CC} ${FLAGS} -I$(INCLUDES_DIR) -c $< -o $@


${NAME}:	${OBJS} 
			${CC} ${FLAGS} ${OBJS} -ggdb -o ${NAME}

all:		${NAME}

clean:
			rm -rf ${OBJS}
			rm -rf index*

fclean:		clean
			rm -rf ${NAME}
			rm -rf ${OBJS_DIR}

re:			fclean all
		
.PHONY: all clean fclean re	