/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:52:27 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/08 02:45:17 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**c_envp(t_env *env_list)
{
	int		i;
	char	**envp;
	char	*tmp;
	t_env	*temp;

	i = count_env_list(env_list);
	envp = (char **)malloc(sizeof(char *) * (i + 1));
	temp = env_list;
	i = 0;
	while (temp)
	{
		envp[i] = ft_strjoin2(temp->key, "=");
		tmp = ft_strdup(envp[i]);
		free(envp[i]);
		envp[i] = ft_strjoin2(tmp, temp->value);
		free(tmp);
		i++;
		temp = temp->next;
	}
	envp[i] = NULL;
	return (envp);
}

void	exec_builtins(t_cmds *cmd, t_tools *t, int builtin)
{
	if (builtin == 1)
	{
		export(t, cmd);
	}
	else if (builtin == 2)
		unset(t, cmd);
	else if (builtin == 3)
		ft_cd(cmd->new_args[1], t);
	else if (builtin == 4)
		pwd();
	else if (builtin == 5)
		echo(cmd->new_args);
	else if (builtin == 6)
		env(t->env_list);
	else if (builtin == 7)
		ft_exit(cmd->new_args);
	else if (builtin == 9)
		print_export(t);
}

void	add_filename_toargs(t_cmds *cmd, char *filename)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!cmd->new_args)
		return ;
	while (cmd->new_args[i])
		i++;
	tmp = cmd->new_args;
	cmd->new_args = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (tmp[i])
	{
		cmd->new_args[i] = ft_strdup(tmp[i]);
		i++;
	}
	cmd->new_args[i] = ft_strdup(filename);
	cmd->new_args[i + 1] = NULL;
}

void	check_here_doc(t_redir *red)
{
	t_redir	*tmp;
	t_redir	*last_herdoc;

	tmp = red;
	last_herdoc = NULL;
	while (tmp)
	{
		if (tmp->operator == 5)
		{
			if (last_herdoc)
				last_herdoc->operator = -1;
			last_herdoc = tmp;
		}
		tmp = tmp->next;
	}
}
