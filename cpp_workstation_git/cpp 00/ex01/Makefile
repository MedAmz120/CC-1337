NAME 	= phonebook
HEAD	= phonebook.hpp
COMPILE = c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
SRC		= main.cpp tools.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(COMPILE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean
