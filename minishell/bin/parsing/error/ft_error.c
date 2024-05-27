/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:58:10 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/06 22:52:16 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_error_parser_dblopr(t_tools *t, t_tokens opr)
{
	ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
	if (opr == PIPE)
		ft_putstr_fd ("'|'\n", 2);
	else if (opr == OUT)
		ft_putstr_fd ("'>'\n", 2);
	else if (opr == OUT_OUT)
		ft_putstr_fd ("'>>'\n", 2);
	else if (opr == INP)
		ft_putstr_fd ("'<'\n", 2);
	else if (opr == INP_INP)
		ft_putstr_fd ("'<<'\n", 2);
	else
		ft_putstr_fd ("\n", 2);
	t->exit_status = 258;
	t->error = -1;
}

void	ft_error(int error_code, t_tools *t)
{
	ft_putstr_fd ("minishell: ", 2);
	if (error_code == 1)
		ft_putstr_fd("-bash: unexpected EOF while looking for matching `\"'\n", \
		2);
	if (error_code == 2)
		ft_putstr_fd("syntax error near unexpected token 'newline'\n", 2);
	if (error_code == 404)
		ft_putstr_fd("command not found\n", 2);
	t->error = -1;
}
