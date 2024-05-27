# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 13:51:05 by moamzil           #+#    #+#              #
#    Updated: 2024/05/06 13:51:05 by moamzil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= Fixed
COMPILE = c++ -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Fixed.cpp
OBJ		= $(SRC:.cpp=.o)
HEAD	= Fixed.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEAD)
	$(COMPILE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean
