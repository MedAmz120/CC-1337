/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:23:39 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/08 02:41:48 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	free_tools_struct(t_tools *t)
{
	if (t->rline)
		free(t->rline);
	if (t->paths)
		free_2darr(t->paths, t);
	if (t->envp)
		free_2darr(t->envp, t);
	if (t->pwd)
		free(t->pwd);
	if (t->old_pwd != NULL)
		free(t->old_pwd);
	if (t->env_name)
		free(t->env_name);
	t->rline = NULL;
	t->pwd = NULL;
	t->old_pwd = NULL;
}

void	free_reds_nodes(t_redir *red, t_tools *t)
{
	t_redir	*temp;

	while (red)
	{
		if (red->file)
			free(red->file);
		if (red->hrd_lines)
			free_2darr(red->hrd_lines, t);
		temp = red;
		red = red->next;
		free(temp);
	}
	red = NULL;
}

void	free_cmds_nodes(t_cmds *cmds, t_tools *t)
{
	t_cmds	*temp;

	while (cmds != NULL)
	{
		if (cmds->cmd)
			free(cmds->cmd);
		if (cmds->args)
			free_2darr(cmds->args, t);
		if (cmds->file)
			free(cmds->file);
		if (cmds->red)
			free_reds_nodes(cmds->red, t);
		if (cmds->new_args)
			free_2darr(cmds->new_args, t);
		temp = cmds;
		cmds = cmds->next;
		if (temp)
			free(temp);
		temp = NULL;
	}
	cmds = NULL;
}

void	free_env_list(t_env *env)
{
	t_env	*temp;

	while (env != NULL)
	{
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
		temp = env;
		env = env->next;
		free(temp);
	}
	env = NULL;
}

void	quit_program(t_tools *t, int S_F)
{
	if (t->env_list)
		free_env_list(t->env_list);
	if (t->lexer_list)
		free_node(t->lexer_list);
	if (t->s_cmds)
		free_cmds_nodes(t->s_cmds, t);
	free_tools_struct(t);
	if (S_F == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
