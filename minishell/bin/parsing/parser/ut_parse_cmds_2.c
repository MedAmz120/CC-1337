/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_parse_cmds_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:46:08 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/08 02:39:26 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

size_t	ft_strlen_skip_v2(char *str)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != DOUBLE_Q && str[i] != SINGLE_Q)
			len++;
		i++;
	}
	return (len);
}

void	fill_args_nr(t_cmds *temp, t_lexer *lexer, t_tools *t)
{
	char	*tmp;
	char	**d2_tmp;

	d2_tmp = NULL;
	if (lexer->next->str)
		tmp = ft_expandit(lexer->next->str, t);
	else
		tmp = NULL;
	d2_tmp = realloc_2d(temp->args, tmp, t);
	temp->args = ft_2dup(d2_tmp);
	free_2darr (d2_tmp, t);
}

void	initialize_command(t_lexer *lexer, t_tools *t, t_cmds *temp)
{
	temp = init_cmd(lexer, t);
}
