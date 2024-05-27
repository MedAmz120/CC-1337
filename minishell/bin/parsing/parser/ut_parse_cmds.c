/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_parse_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:50:14 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/08 00:47:15 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	link_redir_list(t_redir **head, t_redir *temp)
{
	t_redir	*p;

	if (*head == NULL)
		*head = temp;
	else
	{
		p = *head;
		while (p->next != NULL)
			p = p->next;
		p->next = temp;
	}
}

t_redir	*add_redirection_node(t_tokens opr, char *arg)
{
	t_redir	*red;

	red = (t_redir *)malloc(sizeof(t_redir));
	if (arg)
		red->file = ft_strdup(arg);
	else
		red->file = NULL;
	if (!red)
		return (0);
	if (!red->file)
		return (0);
	red->operator = opr;
	red->next = NULL;
	red->hrd_lines = NULL;
	return (red);
}

char	*remove_quotes_from(char *cmd)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = -1;
	new = ft_calloc(ft_strlen_skip_v2(cmd) + 1, sizeof(char));
	while (cmd[i])
	{
		if (cmd[i] != SINGLE_Q && cmd[i] != DOUBLE_Q)
			new[++j] = cmd[i];
		i++;
	}
	free(cmd);
	cmd = ft_strdup(new);
	free(new);
	return (cmd);
}

t_cmds	*init_cmd(t_lexer *lexer, t_tools *t)
{
	t_cmds	*cmd;
	char	*tmp;

	cmd = (t_cmds *)malloc(sizeof(t_cmds));
	if (!cmd)
		return (0);
	if (lexer->str)
	{
		tmp = remove_quotes_from(ft_expandit(lexer->str, t));
		cmd->cmd = ft_strdup(tmp);
		free(tmp);
	}
	else
		cmd->cmd = NULL;
	cmd->file = NULL;
	cmd->red = NULL;
	cmd->is_pipe = 0;
	cmd->args = NULL;
	cmd->next = NULL;
	cmd->prev = NULL;
	cmd->new_args = NULL;
	return (cmd);
}

void	link_cmds_list(t_cmds **head, t_cmds *temp)
{
	t_cmds	*p;

	if (*head == NULL)
		*head = temp;
	else
	{
		p = *head;
		while (p->next != NULL)
			p = p->next;
		p->next = temp;
	}
}
