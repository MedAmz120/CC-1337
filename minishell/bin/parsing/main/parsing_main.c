/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:19:39 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/08 02:42:05 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	add_program_to_args(t_cmds *cmd)
{
	int	i;

	i = 0;
	if (!cmd->args && !cmd->cmd)
		return ;
	while (cmd->args && cmd->args[i])
		i++;
	cmd->new_args = malloc(sizeof(char *) * (i + 2));
	i = 0;
	if (cmd->cmd)
		cmd->new_args[i] = ft_strdup(cmd->cmd);
	if (cmd->args)
	{
		i = 1;
		while (cmd->args && cmd->args[i - 1])
		{
			cmd->new_args[i] = ft_strdup(cmd->args[i - 1]);
			i++;
		}
		cmd->new_args[i] = NULL;
	}
	else
		cmd->new_args[i + 1] = NULL;
}

void	dup_inside_list(t_cmds *cmd)
{
	t_cmds	*head;

	head = cmd;
	while (head)
	{
		add_program_to_args(head);
		head = head->next;
	}
}

void	init_parse(t_tools *t, char **envp)
{
	ft_initialize(t);
	t->envp = ft_2dup(envp);
	ft_env_tolist(t);
	find_pwd(t);
	find_env_path(t);
	signals();
}

void	ft_parsing(t_tools *t, char **envp, int fd0, int fd1)
{
	init_parse(t, envp);
	while (1)
	{
		dup2(fd0, 0);
		dup2(fd1, 1);
		t->rline = readline(READLINE_PROM);
		if (!t->rline)
			break ;
		if (check_empty_cmd(t))
		{
			add_history(t->rline);
			if (!count_double_quotes(t->rline))
				ft_error(1, t);
			if (!ft_token(t))
				ft_error(1, t);
			t->s_cmds = ft_parser(t);
			dup_inside_list(t->s_cmds);
			if (t->error != -1)
				execute(t->s_cmds, t);
			re_init(t);
		}
	}
}
