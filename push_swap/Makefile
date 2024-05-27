# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 12:48:53 by moamzil           #+#    #+#              #
#    Updated: 2023/09/10 06:50:39 by moamzil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	= -Wall -Wextra -Werror
CC		= cc
AR		= ar cr
RM		= rm -rf
NAME	= push_swap
BIN		= bin
FILE	= $(addprefix $(BIN)/, main arg_check tools check_sorted ft_operations_1 ft_operations_2 ft_operations_3 push_swap ft_sort_3 ft_sort_5 ft_sort_100 ft_sort_500 tools_2 tools_3 tools_4)
HEAD	= include/push_swap.h
LIBFT	= src/libft
PRINTF	= src/ft_printf
GNL		= src/get_next_line
SRC		= src/libft/libft.a src/ft_printf/ft_printf.a src/get_next_line/gnl.a
OBJ		= $(FILE:=.o)
ARC		= bin/p_s.a
CLN		= make clean -C
FLN		= make fclean -C

HEADBONUS	= include/push_swap_bonus.h
BINBONUS	= bonus_bin
FILEBONUS	= $(addprefix $(BINBONUS)/, main_bonus checker_bonus arg_check_bonus check_sorted_bonus ft_operations_1_bonus ft_operations_2_bonus ft_operations_3_bonus tools_bonus tools_bonus_1)	
OBJBONUS	= $(FILEBONUS:=.o)
ARCBONUS	= bonus_bin/checker.a
NAMEBONUS	= checker


all: $(ARC) $(SRC)
	$(CC) $(FLAGS) $(SRC) $(ARC) -o $(NAME)

$(ARC): $(OBJ)
	$(AR) $(ARC) $(OBJ)

$(SRC):
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@make -C $(GNL)

%.o: %.c $(HEAD) $(HEADBONUS)
	$(CC) $(FLAFGS) -c $< -o $@

bonus: $(ARCBONUS) $(SRC)
	$(CC) $(FLAGS) $(SRC) $(ARCBONUS) -o $(NAMEBONUS)
	
$(ARCBONUS): $(OBJBONUS) $(SRC)
	$(AR) $(ARCBONUS) $(OBJBONUS)


clean:
	@$(RM) $(ARC)
	@$(RM) $(OBJ)
	@$(RM) $(ARCBONUS)
	@$(RM) $(OBJBONUS)
	@$(CLN) $(LIBFT)
	@$(CLN) $(GNL)
	@$(CLN) $(PRINTF)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAMEBONUS)
	@$(FLN) $(LIBFT)
	@$(FLN) $(GNL)
	@$(FLN) $(PRINTF)

re: fclean all
Phony: all clean fclean re
