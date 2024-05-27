CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putunbr.c ft_adress.c ft_putnbr.c ft_putstr.c
OBJS=${SRCS:.c=.o}
NAME=libftprintf.a
AR=ar -rcs

all:${NAME}

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

${NAME}:${OBJS}
	$(AR) ${NAME} $^

clean:
	rm -rf ${OBJS}

fclean:
	rm -rf ${OBJS} ${NAME}

re: clean all
