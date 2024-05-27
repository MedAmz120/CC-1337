/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:55:55 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/03 19:55:56 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

typedef enum s_tokens
{
	PIPE = 1,
	OUT,
	OUT_OUT,
	INP,
	INP_INP,
}	t_tokens;

typedef struct s_lexer
{
	char			*str;
	int				i;
	t_tokens		token;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_redir
{
	int				operator;
	char			*file;
	char			**hrd_lines;
	struct s_redir	*next;
}	t_redir;

#endif