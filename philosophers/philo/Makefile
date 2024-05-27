# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 11:17:47 by moamzil           #+#    #+#              #
#    Updated: 2023/10/05 20:30:06 by moamzil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Paths and source Files
HEAD	= philo.h
FILE	= arg_convers arg_parsing main tools philosophers tools_2 actions
OBJ		= $(FILE:=.o)
ARC		= philosophers.a
NAME	= philo
# Commands
AR		= ar cr
FLAGS	= -Wall -Wextra -Werror -fsanitize=address -g
CC		= cc
RM		= rm -rf

all: $(NAME)

$(NAME): $(ARC)

$(ARC): $(OBJ)
	$(AR) $(ARC) $(OBJ)
	$(CC) $(FLAGS) $(ARC) -o $(NAME)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(ARC)
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
Phony: all clean fclean re
