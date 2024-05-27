/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_parser_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:52:04 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/05 22:22:12 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	check_n_1(t_lexer *lx, t_tools *t)
{
	if (lx->next == NULL || lx->next->token == PIPE)
	{
		ft_error(2, t);
		return (0);
	}
	if (lx->next != NULL && lx->next->token > 1 && lx->next->token < 6)
	{
		ft_error_parser_dblopr (t, lx->next->token);
		return (0);
	}
	return (1);
}

int	check_n_2(t_lexer *lx, t_tools *t)
{
	if (lx->next == NULL)
	{
		ft_error(2, t);
		return (0);
	}
	if (lx->next != NULL && lx->next->token == PIPE)
	{
		ft_error_parser_dblopr (t, lx->next->token);
		return (0);
	}
	return (1);
}

int	double_check_errors(t_lexer *lexer, t_tools *t)
{
	t_lexer	*lx;

	lx = lexer;
	if (t->error == -1)
		return (0);
	while (lx)
	{
		if (lx->token > 1 && lx->token < 6)
			if (!check_n_1(lx, t))
				break ;
		if (lx->token == PIPE)
			if (!check_n_2(lx, t))
				break ;
		lx = lx->next;
	}
	return (1);
}

int	ft_check_pipes(t_tools *t, t_tokens opr)
{
	if (opr == PIPE)
	{
		ft_error_parser_dblopr (t, PIPE);
		return (0);
	}
	if (!t->lexer_list)
	{
		ft_error (2, t);
		return (0);
	}
	return (1);
}
