# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 17:07:15 by moamzil           #+#    #+#              #
#    Updated: 2023/12/08 00:58:58 by rrakman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Paths and source Files
HEAD	= include/minishell.h
FILE	=	bin/main.c \
			bin/parsing/main/parsing_main.c \
			bin/parsing/main/quit_program.c \
			bin/parsing/main/ut_quit_program.c \
			bin/parsing/error/ft_error.c \
			bin/parsing/tokenizer/ft_token.c \
			bin/parsing/tokenizer/ut_token.c \
			bin/parsing/utils/common.c \
			bin/parsing/utils/utils_1.c \
			bin/parsing/utils/utils_2.c \
			bin/parsing/parser/ft_parser.c \
			bin/parsing/parser/ut_parser.c \
			bin/parsing/parser/ut_parser_2.c \
			bin/parsing/parser/env_to_list.c \
			bin/parsing/parser/parse_cmds.c \
			bin/parsing/parser/ut_parse_cmds.c \
			bin/parsing/parser/ut_parse_cmds_2.c \
			bin/parsing/expand/ft_expand.c \
			bin/parsing/expand/ut_expand.c \
			bin/parsing/expand/ut_expand_2.c \
			bin/exec/execute.c \
			bin/exec/builtin/echo.c \
			bin/exec/builtin/exit.c \
			bin/exec/builtin/pwd.c \
			bin/exec/builtin/cd.c \
			bin/exec/builtin/export.c \
			bin/exec/builtin/unset.c \
			bin/exec/builtin/env.c \
			bin/exec/builtin/cd_utils.c \
			bin/exec/builtin/export_utils.c \
			bin/exec/exec_utils.c \
			bin/exec/exec_utils_2.c \
			bin/exec/handle_redir.c \
			bin/exec/exec_utils_3.c \
			bin/parsing/main/signals.c
OBJ		= $(patsubst bin/%.c, bin/%.o, $(FILE))
SRC		= src/libft/libft.a
ARC		= bin/minishell.a
NAME	= minishell

LIBFT	= src/libft

# Commands
AR		= ar cr
FLAGS	= -Wall -Wextra -Werror -I/Users/rrakman/.brew/opt/readline/include/
RM		= rm -rf
MK		= make -C
MCLN	= make clean -C
MFCLN	= make fclean -C

all: $(NAME)

$(NAME): $(ARC)

$(ARC): $(OBJ) $(SRC)
	$(AR) $(ARC) $(OBJ)
	$(CC) $(ARC) $(FLAGS) $(SRC) -o $(NAME) -lreadline -lreadline -L/Users/rrakman/.brew/opt/readline/lib/

$(SRC):
	$(MK) $(LIBFT)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(ARC)
	@$(RM) $(OBJ)
	@$(MCLN) $(LIBFT)

fclean: clean
	@$(RM) $(NAME)
	@$(MFCLN) $(LIBFT)

re: fclean all
Phony: all clean fclean re
