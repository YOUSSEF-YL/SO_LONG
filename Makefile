SRCS = 
OBJS	= ${SRCS:.c=.o}
NAME	= 
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