/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 00:24:18 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/08 00:05:42 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_list(t_env *env_list)
{
	t_env	*temp;

	while (env_list)
	{
		temp = env_list;
		env_list = env_list->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = 0;
	return (str);
}

char	*find_path(char *cmd, char **paths)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	if (!cmd)
	{
		free(cmd);
		return (NULL);
	}
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin2(paths[i], "/");
		tmp2 = ft_strjoin2(tmp, cmd);
		free(tmp);
		if (access(tmp2, F_OK) == 0)
			return (tmp2);
		free(tmp2);
		i++;
	}
	return (cmd);
}

int	is_builtin(t_cmds *cmd, t_tools *t)
{
	(void) t;
	if (mystrcmp(cmd->cmd, "export") == 0 && cmd->new_args[1] != NULL)
		return (1);
	else if (mystrcmp(cmd->cmd, "unset") == 0)
		return (2);
	else if (mystrcmp(cmd->cmd, "cd") == 0)
		return (3);
	else if (mystrcmp(cmd->cmd, "pwd") == 0)
		return (4);
	else if (mystrcmp(cmd->cmd, "echo") == 0)
		return (5);
	else if (mystrcmp(cmd->cmd, "env") == 0)
		return (6);
	else if (mystrcmp(cmd->cmd, "exit") == 0)
		return (7);
	else if (mystrcmp(cmd->cmd, "export") == 0 && !cmd->new_args[1])
		return (9);
	else
		return (8);
}

int	count_env_list(t_env *env_list)
{
	int		i;
	t_env	*temp;

	temp = env_list;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
