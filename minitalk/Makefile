# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 18:30:11 by moamzil           #+#    #+#              #
#    Updated: 2023/01/16 13:30:22 by moamzil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=CC
FLAGS= -Wall -Werror -Wextra -I libft.h
AR=ar cr
RM=rm -rf
FILES= ft_putchar_fd ft_putnbr_fd ft_putstr_fd ft_atoi client server
BONUS_F= ft_putchar_fd ft_putnbr_fd ft_putstr_fd ft_atoi client_bonus server_bonus
OBJ=$(FILES:=.o)
OBJ_BONUS=$(BONUS_F:=.o)
NAME=minitalk.a
OUT= client client_bonus server_bonus server

.PHONY: all bonus clean fclean re

all: $(NAME)
	@echo "Done !"
$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(CC) client.c $(NAME) -o client
	@$(CC) server.c $(NAME) -o server

%.o: %.c minitalk.h minitalk_bonus.h
	@echo "Compilation ..."
	@$(CC) $(FLAGS) -c $< -o $@
bonus: $(OBJ_BONUS)
	@$(AR) $(NAME) $(OBJ_BONUS)
	@$(CC) client_bonus.c $(NAME) -o client_bonus
	@$(CC) server_bonus.c $(NAME) -o server_bonus
	@echo "Done with Bonus !"
clean:
	@echo "CLeaned"
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@$(RM) $(NAME) $(OUT)

re: fclean all
