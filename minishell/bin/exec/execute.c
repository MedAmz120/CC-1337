/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:30 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/07 18:40:19 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	waitforchilds(t_cmds *tmp, t_tools *t)
{
	while (tmp)
	{
		waitpid(-1, &t->exit_status, 0);
		if (WEXITSTATUS(t->exit_status))
			t->exit_status = WEXITSTATUS(t->exit_status);
		tmp = tmp->next;
	}
}

int	execute(t_cmds *cmd, t_tools *t)
{
	int		builtin;
	t_cmds	*node;
	t_cmds	*tmp;
	pid_t	pid;

	node = cmd;
	tmp = cmd;
	t->fd_prev[0] = -1;
	t->fd_prev[1] = -1;
	while (node)
	{
		norm_exec5(node, t, &builtin, t->fd);
		pid = fork();
		if (pid == 0)
		{
			norm_exec2(t->fd_prev, t->fd, node);
			norm_exec3(node, &builtin, t);
		}
		else
			norm_exec4(t->fd_prev, t->fd);
		node = node->next;
	}
	waitforchilds(tmp, t);
	return (0);
}
