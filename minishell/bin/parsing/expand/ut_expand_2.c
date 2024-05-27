/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_expand_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:08:32 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/04 20:04:37 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	quotes_backslash(char *str, t_tools *t, char *res)
{
	char	*tmp;

	tmp = NULL;
	if (str == NULL)
		return ;
	if (str[0] == DOUBLE_Q || str[0] == SINGLE_Q)
	{
		tmp = remove_double_quotes(str, t);
		free(str);
		str = NULL;
		str = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
	}
	if (res)
		free(res);
}

int	assign_single(char *str, int i, t_tools *t)
{
	if (str[i] == SINGLE_Q)
		if (t->in_double_quotes == 1)
			return (1);
	return (0);
}

int	assign_double(char *str, int i)
{
	if (str[i] == DOUBLE_Q)
		if ((i == 0 || str[i - 1] != '\\') && i != ((int)ft_strlen(str) - 1))
			return (1);
	return (0);
}

int	assign_random(char *str, int i)
{
	if (str[i] != '\\' && str[i] != DOUBLE_Q && str[i] != SINGLE_Q)
		return (1);
	return (0);
}
