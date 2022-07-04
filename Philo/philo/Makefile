# this is to manage flags for m1 architecture, we don't have to use this flag in linux
OS_ARCH 	:= $(shell uname -m)

HEADER_INC	:=	-I.

SRC_PATH	=	./

SRCS		=	philo.c args.c time.c watch.c init.c action.c 

OBJ_PATH	=	./bin/

OBJS		=	$(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

CC			=	gcc

# CFLAGS		=	-Wall -Werror -Wextra -g3 -fsanitize=address
CFLAGS		=	-Wall -Wextra -Werror -pthread -g3 -fsanitize=thread

NAME		=	philo

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@printf "\033[94m.\033[0m"
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CFLAGS) -c $< -o $@ $(HEADER_INC)


$(NAME):		$(OBJS)
				@echo "\033[94m\n\nObject files has been compiled! \033[0m"
				@echo "\033[95m\nGenerating executable on $(OS_ARCH) ...\033[0m"
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 
				@echo "\033[92m\n$(NAME) for $(OS_NAME) has been created! \033[0m"

all:			$(NAME)

clean:
				@rm -rf $(OBJ_PATH)
				@echo "\033[91m\nObject files has been removed.\033[0m"

fclean:			clean
				@rm -f $(NAME)
				@echo "\033[91m\nExecutable file has been removed.\n\033[0m"

re: 			fclean all


.PHONY:			all clean fclean re bonus
