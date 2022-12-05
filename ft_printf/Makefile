
MAIN		= main.c
OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -Rf
LIB			= ar rc
INC			= includes
A_OUT		= a.out a.out.dSYM
SRCS		= ft_printf.c ft_utils.c ft_sort.c ft_hexa.c

.c.o:		${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INC}

all:		${NAME}

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS} ${A_OUT} ft_printf.h.gch

fclean:		clean
			${RM} ${NAME}

re:			fclean all

run:		all
			${CC} -g ${FLAGS} ${MAIN} ft_printf.c -L. -lftprintf
			./${A_OUT}

.PHONY:		all clean flcean re
