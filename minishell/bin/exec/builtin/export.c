/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:43:08 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/08 02:44:35 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	add_node_to_env_list(t_env **env_list, char *key, char *value)
{
	t_env	*temp;
	t_env	*new_node;

	temp = *env_list;
	new_node = (t_env *)malloc(sizeof(t_env));
	new_node->key = ft_strdup(key);
	if (value == NULL)
		new_node->value = NULL;
	else
		new_node->value = ft_strdup(value);
	new_node->next = NULL;
	if (*env_list == NULL)
		*env_list = new_node;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	export_error(t_tools *t, t_cmds *cmd, int i)
{
	t->exit_status = 1;
	ft_putstr_fd("export: ", 2);
	ft_putstr_fd(cmd->new_args[i], 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
}

void	norm(t_tools *t, t_cmds *cmd, int i)
{
	char	*key;
	char	*value;

	key = ft_substr(cmd->new_args[i], 0, ft_strlen(cmd->new_args[i]));
	value = NULL;
	add_node_to_env_list(&(t->env_list), key, value);
	free(key);
	free(value);
}

void	norm2(char *value, char *key, int i, t_tools *t)
{
	key = ft_substr(t->s_cmds->new_args[i], 0, \
		ft_strclen(t->s_cmds->new_args[i], '='));
	value = ft_substr(t->s_cmds->new_args[i], \
		ft_strclen(t->s_cmds->new_args[i], '=') + 1, \
			ft_strlen(t->s_cmds->new_args[i]));
	add_node_to_env_list(&(t->env_list), key, value);
	free(key);
	free(value);
}

void	export(t_tools *t, t_cmds *cmd)
{
	int		i;
	char	*value;
	char	*key;

	i = 1;
	value = NULL;
	key = NULL;
	while (cmd->new_args[i])
	{
		if (!check_export(cmd->new_args[i]))
			export_error(t, cmd, i);
		else
		{
			t->exit_status = 0;
			if (ft_strchr(cmd->new_args[i], '='))
				norm2(value, key, i, t);
			else
				norm(t, cmd, i);
		}
		i++;
	}
}
