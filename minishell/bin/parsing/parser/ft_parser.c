/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:35:42 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/06 22:41:34 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_cmds	*ft_parser(t_tools *t)
{
	t_cmds		*cmds;

	t->pipes = pipes_counter(t->lexer_list);
	cmds = NULL;
	if (t->lexer_list->token == PIPE)
		ft_error_parser_dblopr(t, PIPE);
	if ((t->lexer_list->token == OUT || t->lexer_list->token == OUT_OUT
			|| t->lexer_list->token == INP || t->lexer_list->token == INP_INP)
		&& (t->lexer_list->next == NULL) && t->error != -1)
		ft_error(2, t);
	double_check_errors(t->lexer_list, t);
	if (t->error == -1)
		return (NULL);
	cmds = order_cmds (t->lexer_list, t);
	if (!cmds)
		return (NULL);
	return (cmds);
}
