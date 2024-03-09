
SRCS = 	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_strdup.s \
		ft_write.s \
		ft_read.s

BONUS_SRCS = 	ft_atoi_base_bonus.s \
				ft_list_size_bonus.s \
				ft_list_push_front_bonus.s \
				ft_list_sort_bonus.s \
				ft_list_remove_if_bonus.s

NAME = libasm.a
TEST = test

OBJS_PATH = objs/
SRCS_PATH = src/
BONUS_PATH = bonus/

OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.s=.o))
OBJS_BONUS = $(addprefix $(OBJS_PATH), $(SRCS:.s=.o) $(BONUS_SRCS:.s=.o))

${OBJS_PATH}%.o: ${SRCS_PATH}%.s
		@mkdir -p objs
		nasm -felf64 -o $@ $<

${OBJS_PATH}%.o: ${BONUS_PATH}%.s
		@mkdir -p objs
		nasm -felf64 -o $@ $<

${NAME}: ${OBJS}
		ar -rcs ${NAME} ${OBJS}

all: ${NAME}

bonus: ${OBJS_BONUS}
		@ar -rcs ${NAME} ${OBJS_BONUS}

clean: 
	rm -rf ${OBJS_PATH}

fclean: clean
	rm -rf ${NAME}
	rm -rf ${TEST}

re: fclean all

test: bonus
	@gcc -g -Wall -Wextra -L . -o ${TEST} main.c ${NAME}
	./${TEST}

.PHONY: all clean fclean re test bonus