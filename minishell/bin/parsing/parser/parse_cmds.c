/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:47:51 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/07 14:40:06 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	handle_herdoc(t_redir *red, char *arg, t_tools *t)
{
	char	*line;
	char	*tmp;
	char	*tmp_2;

	line = NULL;
	tmp = NULL;
	tmp_2 = NULL;
	while (1)
	{
		line = readline(">");
		tmp_2 = ft_strdup(line);
		tmp = ft_expandit(tmp_2, t);
		if (!ft_strncmp(line, arg, ft_strlen(arg)))
		{
			free(line);
			if (tmp)
				free(tmp);
			break ;
		}
		red->hrd_lines = realloc_2d(red->hrd_lines, tmp, t);
		if (line)
			free(line);
	}
}

void	ft_file_not_found(t_tools *t, t_cmds *cmd)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd->cmd, STDERR_FILENO);
	ft_putstr_fd("No such file or directory\n", STDERR_FILENO);
	t->error = -1;
	t->exit_status = 1;
}

void	free_tmp_args(t_tools *t, char *arg)
{
	if (arg)
		free(arg);
	if (t->arg_tmp_2)
		free(t->arg_tmp_2);
	if (t->arg_tmp_3)
		free(t->arg_tmp_3);
}

void	ft_redirections(t_cmds *cmd, t_tokens opr, char *arg, t_tools *t)
{
	int		fd;
	t_redir	*tmp;

	fd = 0;
	t->arg_tmp = ft_strdup(arg);
	t->arg_tmp_2 = ft_expandit(t->arg_tmp, t);
	t->arg_tmp_3 = ft_strdup(t->arg_tmp_2);
	tmp = add_redirection_node(opr, t->arg_tmp_2);
	if (cmd->file)
		free(cmd->file);
	cmd->file = ft_strdup(t->arg_tmp_2);
	if (!cmd->file)
		quit_program(t, EXIT_FAILURE);
	if ((access(cmd->file, F_OK) == -1) && opr != INP_INP)
	{
		fd = open(cmd->file, O_CREAT | O_EXCL | O_RDWR);
		if (fd == -1)
			ft_file_not_found(t, cmd);
		close(fd);
	}
	if (opr == INP_INP)
		handle_herdoc(tmp, arg, t);
	link_redir_list(&cmd->red, tmp);
	free_tmp_args(t, arg);
}

t_cmds	*order_cmds(t_lexer *lexer, t_tools *t)
{
	t_cmds	*temp;
	t_cmds	*head;

	temp = NULL;
	head = NULL;
	while (lexer != NULL)
	{
		temp = init_cmd(lexer, t);
		while (lexer->token != PIPE && lexer->next != NULL)
		{
			if (lexer->next && lexer->token == 0 && lexer->next->token == 0)
				temp->args = realloc_2d(temp->args,
						ft_expandit(lexer->next->str, t), t);
			if (lexer->next && lexer->token != 0 && lexer->token != PIPE)
				ft_redirections(temp, lexer->token, lexer->next->str, t);
			lexer = lexer->next;
		}
		link_cmds_list(&head, temp);
		if (lexer->next == NULL)
			break ;
		lexer = lexer->next;
	}
	return (head);
}
