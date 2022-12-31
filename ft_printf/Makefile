SRCS = ft_printf.c ft_putnbr.c ft_putchar.c ft_putstr.c ft_puthex.c ft_puthexp.c ft_putun.c

OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror
RM		= rm -f

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}



clean:
	${RM} ${OBJS}

fclean:
	${RM} ${NAME} ${OBJS}


re:	fclean all