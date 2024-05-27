/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:36:30 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/08 02:44:21 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_export(t_tools *t)
{
	t_env	*temp;

	t->exit_status = 0;
	temp = t->env_list;
	while (t->env_list)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(t->env_list->key, 1);
		if (t->env_list->value != NULL)
		{
			ft_putstr_fd("=", 1);
			if (t->env_list->value[0] == '\0')
				ft_putstr_fd("\"\"\n", 1);
			else
			{
				ft_putstr_fd("\"", 1);
				ft_putstr_fd(t->env_list->value, 1);
				ft_putstr_fd("\"\n", 1);
			}
		}
		else
			ft_putstr_fd("\n", 1);
		t->env_list = t->env_list->next;
	}
	t->env_list = temp;
}

int	check_export(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
		return (0);
	while (str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '=')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
