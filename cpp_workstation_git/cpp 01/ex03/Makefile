NAME 	= Violence
COMPILE = c++ -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean
