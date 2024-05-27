# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 10:55:18 by moamzil           #+#    #+#              #
#    Updated: 2023/08/17 20:56:15 by moamzil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	CC
FLAGS	=	-Wall -Wextra -Werror
AR		=	ar cr
SRCDIR	=	bin
FILES	=	$(addprefix $(SRCDIR)/, so_long change_p_pos check_map counter events init_elements move read_map tools window check_map_path)
SRC		=	src/libft/libft.a src/ft_printf/ft_printf.a src/get_next_line/gnl.a
LIBFT	=	src/libft
PRINTF 	=	src/ft_printf
GNL		=	src/get_next_line
HEAD	=	include/so_long.h
MAP		=	maps/map.ber
OBJ		=	$(FILES:=.o)
ARC		=	bin/so.a
NAME	=	so_long
RM		=	rm -rf
FCLN 	=	make fclean -C
CLN		=	make clean -C

.PHONY:	all clean fclean re

all: $(ARC) $(SRC)
	$(CC) $(FLAGS) $(ARC) $(SRC) -lmlx -framework OpenGL -framework Appkit -o $(NAME)
	@echo "Compilation > Done ! srcs compiled succefully"

$(ARC): $(OBJ)
	$(AR) $(ARC) $(OBJ)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

$(SRC):
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@make -C $(GNL)

clean:
	@$(RM) $(OBJ)
	@$(CLN) $(LIBFT)
	@$(CLN) $(PRINTF)
	@$(CLN) $(GNL)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(ARC)
	@$(FCLN) $(LIBFT)
	@$(FCLN) $(PRINTF)
	@$(FCLN) $(GNL)
	@echo "Cleaning : so_long !"

re: fclean all