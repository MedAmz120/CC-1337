/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:09:28 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/08 01:57:01 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_initialize(t_tools *t)
{
	t->envp = NULL;
	t->env_new = NULL;
	t->lexer_list = NULL;
	t->env_list = NULL;
	t->env_name = NULL;
	t->old_pwd = NULL;
	t->paths = NULL;
	t->pwd = NULL;
	t->rline = NULL;
	t->exit_status = 0;
	t->pipes = 0;
	t->error = 0;
	t->flag = 0;
	t->s_cmds = NULL;
	t->arg_tmp = NULL;
	t->arg_tmp_2 = NULL;
	t->arg_tmp_3 = NULL;
	t->c = 10;
}

t_tokens	check_opr(int c)
{
	int			i;
	static int	tokens[3][2] = {
	{'|', PIPE},
	{'>', OUT},
	{'<', INP},
	};

	i = 0;
	while (i < 3)
	{
		if (tokens[i][0] == c)
			return (tokens[i][1]);
		i++;
	}
	return (0);
}

int	skip_double_single(char *str, int i)
{
	if (str[i] == DOUBLE_Q || str[i] == SINGLE_Q)
	{
		i++;
		while (str[i] != SINGLE_Q && str[i] != DOUBLE_Q && str[i])
			i++;
		if (str[i + 1] != '\0')
			i += 1;
		return (i);
	}
	return (i);
}

int	is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

int	skip_white_spaces(char *str, int pos)
{
	int	j;

	j = 0;
	while (is_whitespace(str[pos + j]))
		j++;
	return (j);
}
