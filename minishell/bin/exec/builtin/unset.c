/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:12:10 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/07 15:51:43 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	mystrcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1 && s2 && s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (1);
}

void	ft_list_remove_if(t_env **env_list, char *key_to_unset)
{
	t_env	*curr;
	t_env	*prev;

	if (env_list == NULL || *env_list == NULL)
		return ;
	curr = *env_list;
	prev = NULL;
	while (curr)
	{
		if (mystrcmp(curr->key, key_to_unset) == 0)
		{
			if (prev == NULL)
				*env_list = curr->next;
			else
				prev->next = curr->next;
			free(curr->key);
			free(curr->value);
			free(curr);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
}

void	unset(t_tools *t, t_cmds *cmd)
{
	int		i;
	char	*key_to_unset;
	t_env	*curr;

	i = 1;
	while (cmd->new_args[i])
	{
		key_to_unset = cmd->new_args[i];
		curr = t->env_list;
		while (curr)
		{
			if (mystrcmp(curr->key, key_to_unset) == 0)
				break ;
			curr = curr->next;
		}
		if (curr)
			ft_list_remove_if(&(t->env_list), key_to_unset);
		i++;
	}
}
