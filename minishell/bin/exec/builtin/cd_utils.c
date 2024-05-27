/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:57:29 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/07 15:06:19 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_env	*init_old_pwd(char *key, char *value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

void	add_oldpwd_tomyenv(char *key, char *value, t_tools *t)
{
	t_env	*new;
	t_env	*temp;
	int		flag;

	flag = 0;
	temp = t->env_list;
	while (temp)
	{
		if (ft_strcmp(temp->key, key) == 0)
		{
			flag = 1;
			free(temp->value);
			temp->value = ft_strdup(value);
			break ;
		}
		temp = temp->next;
	}
	if (flag == 0)
	{
		new = init_old_pwd(key, value);
		temp = t->env_list;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
