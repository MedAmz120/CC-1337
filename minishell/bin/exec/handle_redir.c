/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:35:44 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/08 00:36:39 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_input(char *file, t_tools *t, int fd)
{
	if (access(file, F_OK) != 0)
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		t->error = 1;
	}
	else
	{
		fd = open(file, O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

void	handle_heredoc_norm(t_redir *red, t_cmds *cmd)
{
	int		i;
	int		fd_here_doc;
	char	*filename;

	i = 0;
	fd_here_doc = open("/tmp/herdoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (red->hrd_lines && red->hrd_lines[i])
	{
		write(fd_here_doc, red->hrd_lines[i], ft_strlen(red->hrd_lines[i]));
		write(fd_here_doc, "\n", 1);
		i++;
	}
	filename = "/tmp/herdoc";
	add_filename_toargs(cmd, filename);
	dup2(fd_here_doc, STDIN_FILENO);
	close(fd_here_doc);
}

void	handle_redirection(t_redir *red, t_cmds *cmd, t_tools *t)
{
	int	fd;

	while (red)
	{
		if (red->operator == 2)
		{
			fd = open(red->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		else if (red->operator == 3)
		{
			fd = open(red->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		else if (red->operator == 4)
			handle_input(red->file, t, fd);
		else if (red->operator == 5)
			handle_heredoc_norm(red, cmd);
		red = red->next;
	}
}
