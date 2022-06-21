NAME = push_swap

HEADERS = pushswap.h

SRCS = ft_parsing.c ft_stack_utils.c operation.c push_swap.c ft_checkbestmove.c \
	ft_new_lis.c push_swap_utils.c ft_posi.c ft_divers.c ft_split.c ft_low_arg.c

OBJETS = ${SRCS:%.c=./.build/%.o}

FT_PRINTF = cd ft_printf && make re

CC = gcc

FLAGS = -Wall -Werror -Wextra

./.build/%.o : %.c
	${CC} -I. -o $@ -c $? ${FLAGS}

${NAME}	 : ${OBJETS}
		${FT_PRINTF}
		${CC} -o ${NAME} ${OBJETS} ft_printf/libftprintf.a

all: 
	mkdir -p .build
	make ${NAME}

clean :
	rm -rf .build

fclean : clean
	cd ft_printf && make fclean
	rm -rf ${NAME}

re :  fclean all

PHONY = all clean fclean re
