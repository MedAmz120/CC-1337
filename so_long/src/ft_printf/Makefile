# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 11:21:27 by moamzil           #+#    #+#              #
#    Updated: 2023/08/02 11:25:54 by moamzil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putunbr.c ft_adress.c ft_putnbr.c ft_putstr.c
OBJS=${SRCS:.c=.o}
NAME=ft_printf.a
AR=ar -rcs

.PHONY:	all clean fclean re

all:${NAME}

%.o:%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

${NAME}:${OBJS}
	@$(AR) ${NAME} $^

clean:
	@rm -rf ${OBJS}

fclean:
	@rm -rf ${OBJS} ${NAME}
	@echo "Cleaning : ft_printf !"

re: clean all
