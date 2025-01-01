# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 13:14:46 by moamzil           #+#    #+#              #
#    Updated: 2024/12/31 16:14:05 by moamzil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 	= Serializer
COMPILE = c++ -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Serializer.cpp
OBJ		= $(SRC:.cpp=.o)
HEAD	= Serializer.hpp

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
