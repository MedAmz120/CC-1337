/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:56:43 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/03 21:56:45 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	tokenize(char *str, int i, t_lexer **lexer_list)
{
	t_tokens	token;

	token = check_opr(str[i]);
	if (token == OUT && check_opr(str[i + 1]) == OUT)
	{
		if (!add_node(NULL, OUT_OUT, lexer_list))
			return (-1);
		return (2);
	}
	else if (token == INP && check_opr(str[i + 1]) == INP)
	{
		if (!add_node(NULL, INP_INP, lexer_list))
			return (-1);
		return (2);
	}
	else if (token)
	{
		if (!add_node(NULL, token, lexer_list))
			return (-1);
		return (1);
	}
	return (0);
}

int	read_words(int i, char *str, t_lexer **lexer_list)
{
	int	j;

	j = 0;
	while (str[i + j] && !(check_opr(str[i + j])))
	{
		j += handle_quotes(i + j, str, DOUBLE_Q);
		j += handle_quotes(i + j, str, SINGLE_Q);
		if (is_whitespace(str[i + j]))
			break ;
		else
			j++;
	}
	if (!add_node(ft_substr(str, i, j), 0, lexer_list))
		return (-1);
	return (j);
}

int	ft_token(t_tools *t)
{
	int	i;
	int	j;

	i = 0;
	while (t->rline[i])
	{
		j = 0;
		i += skip_white_spaces(t->rline, i);
		if (check_opr(t->rline[i]))
			j = tokenize(t->rline, i, &t->lexer_list);
		else
			j = read_words(i, t->rline, &t->lexer_list);
		if (j < 0)
			return (0);
		i += j;
	}
	return (1);
}
