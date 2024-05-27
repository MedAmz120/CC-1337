NAME 	= harlFilter
COMPILE = c++ -W -W -W -std=c++98
SRC		= main.cpp Harl.cpp
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
