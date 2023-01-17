# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 19:42:52 by ybachar           #+#    #+#              #
#    Updated: 2023/01/16 21:52:20 by ybachar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= get_next_line.c get_next_line_utils.c hooks.c map_checker.c so_long_util.c so_long.c so_long_util_t.c

OBJS	= ${SRCS:.c=.o}

NAME	= so_long

CC		= gcc

CFLAGS 	= -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

RM		= rm -f

$(NAME) : ${SRCS}
	make -C ft_printf
	${CC} ${CFLAGS} ${SRCS} ./ft_printf/libftprintf.a -o so_long

all: ${NAME}

clean:
	make clean -C ft_printf
	${RM} so_long

fclean: clean
	make fclean -C ft_printf


re:	fclean all