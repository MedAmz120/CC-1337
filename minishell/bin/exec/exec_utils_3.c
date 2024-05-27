/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:38:48 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/08 02:45:00 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	norm_exec(t_cmds *node, t_tools *t, int *builtin)
{
	char	*tmp;

	if (node->red)
	{
		check_here_doc(node->red);
		handle_redirection(node->red, node, t);
	}
	if (node->cmd != NULL && node->new_args != NULL)
		*builtin = is_builtin(node, t);
	if (((*builtin <= 3 && *builtin > 0) || *builtin == 7) && node->cmd != NULL
		&& node->new_args != NULL)
		exec_builtins(node, t, *builtin);
	if (node->cmd && node->new_args && *builtin == 8)
	{
		tmp = node->cmd;
		node->cmd = find_path(node->new_args[0], t->paths);
		if (tmp)
			free(tmp);
	}
}

void	norm_exec2(int *fd_prev, int *fd, t_cmds *node)
{
	if (fd_prev[0] != -1)
	{
		dup2(fd_prev[0], STDIN_FILENO);
		close(fd_prev[0]);
		close(fd_prev[1]);
	}
	if (node->next)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	close(fd[0]);
	close(fd[1]);
}

void	norm_exec3(t_cmds *node, int *builtin, t_tools *t)
{
	if (((*builtin < 7 && *builtin > 3) || *builtin == 9) && node->cmd != NULL
		&& node->new_args != NULL)
		exec_builtins(node, t, *builtin);
	t->env_new = c_envp(t->env_list);
	if ((node->cmd || node->new_args) && *builtin == 8)
	{
		t->exit_status = 0;
		if (execve(node->cmd, node->new_args, t->env_new) == -1)
		{
			ft_putstr_fd(node->cmd, 2);
			write(2, " : ", 3);
			write(2, "command not found !\n", 21);
			t->exit_status = 127;
			exit(t->exit_status);
		}
	}
	exit(t->exit_status);
}

void	norm_exec4(int *fd_prev, int *fd)
{
	if (fd_prev[0] != -1)
	{
		close(fd_prev[1]);
		close(fd_prev[0]);
	}
	fd_prev[0] = fd[0];
	fd_prev[1] = fd[1];
}

void	norm_exec5(t_cmds *node, t_tools *t, int *builtin, int *fd)
{
	norm_exec(node, t, builtin);
	pipe(fd);
}
