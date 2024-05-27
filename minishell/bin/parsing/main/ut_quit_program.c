/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_quit_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:25:18 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/08 02:40:41 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	free_node(t_lexer *lexer_list)
{
	t_lexer	*temp;

	while (lexer_list != NULL)
	{
		temp = lexer_list;
		lexer_list = lexer_list->next;
		free(temp);
		temp = NULL;
	}
	lexer_list = NULL;
}

void	free_2darr(char **tab, t_tools *t)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		if (tab[i])
		{
			if (t->exit_status != 127)
				free (tab[i]);
		}
		tab[i] = NULL;
		i++;
	}
	if (tab)
		free (tab);
	tab = NULL;
}

void	re_init_env(t_tools *t)
{
	if (t->envp)
	{
		free_2darr (t->envp, t);
		t->envp = NULL;
		t->envp = ft_2dup (t->env_new);
		free_2darr (t->env_new, t);
		t->env_new = NULL;
	}
}

void	re_init(t_tools *t)
{
	t->error = 0;
	if (t->lexer_list)
		free_node (t->lexer_list);
	if (t->s_cmds)
		free_cmds_nodes (t->s_cmds, t);
	if (t->rline)
		free (t->rline);
	t->lexer_list = NULL;
	if (t->env_name)
		free (t->env_name);
	if (t->env_new)
		re_init_env(t);
	t->env_name = NULL;
	t->rline = NULL;
	t->pipes = 0;
	t->s_cmds = NULL;
}
