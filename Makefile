SRCS = get_next_line.c get_next_line_utils.c hooks.c map_checker.c so_long_util.c so_long.c
OBJS	= ${SRCS:.c=.o}
NAME	= libso_long.a
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