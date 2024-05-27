# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 13:14:46 by moamzil           #+#    #+#              #
#    Updated: 2024/05/19 15:39:49 by moamzil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 	= Animal
COMPILE = c++ -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Animal.cpp Cat.cpp Dog.cpp \
			WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJ		= $(SRC:.cpp=.o)
HEAD	= Animal.hpp Cat.hpp Dog.hpp \
			WrongAnimal.hpp WrongCat.hpp Brain.hpp

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
