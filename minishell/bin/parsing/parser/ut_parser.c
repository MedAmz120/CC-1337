/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:53:33 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/03 21:53:37 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_lexerdelone(t_lexer **lst, int key)
{
	t_lexer	*node;
	t_lexer	*prev;
	t_lexer	*start;

	start = *lst;
	node = start;
	if ((*lst)->i == key)
	{
		ft_lexerdel_first(lst);
		return ;
	}
	while (node && node->i != key)
	{
		prev = node;
		node = node->next;
	}
	if (node)
		prev->next = node->next;
	else
		prev->next = NULL;
	if (prev->next)
		prev->next->prev = prev;
	ft_lexerclear_one(&node);
	*lst = start;
}

t_lexer	*ft_lexerclear_one(t_lexer **lst)
{
	if ((*lst)->str)
	{
		free((*lst)->str);
		(*lst)->str = NULL;
	}
	free(*lst);
	*lst = NULL;
	return (NULL);
}

void	ft_lexerdel_first(t_lexer **lst)
{
	t_lexer	*node;

	node = *lst;
	*lst = node->next;
	ft_lexerclear_one(&node);
	if (*lst)
		(*lst)->prev = NULL;
}

int	pipes_counter(t_lexer *lexer_List)
{
	t_lexer	*tmp;
	int		count;

	count = 0;
	tmp = lexer_List;
	while (tmp != NULL)
	{
		if (tmp->token == PIPE)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
