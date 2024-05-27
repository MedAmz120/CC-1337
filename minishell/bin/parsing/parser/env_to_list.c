/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:30:26 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/03 20:30:27 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	init_key(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i] != '=' && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (++i);
}

void	init_data2(char *line, t_env *env)
{
	int	i;
	int	j;

	j = 0;
	env->key = malloc(sizeof(char) * ft_strllen(line, 0, '=') + 1);
	i = init_key(line, env->key);
	env->value = malloc(sizeof(char) * ft_strllen(line, i, '\0') + 1);
	while (line[i])
	{
		env->value[j] = line[i];
		i++;
		j++;
	}
	env->value[j] = '\0';
}

void	link_list(t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = env;
}

t_env	*ft_init_env_list(int n, t_tools *t)
{
	int		i;
	t_env	*head;
	t_env	*temp;
	t_env	*p;

	i = -1;
	head = NULL;
	temp = NULL;
	p = NULL;
	while (++i < n)
	{
		temp = (t_env *)malloc(sizeof(t_env));
		init_data2 (t->envp[i], temp);
		temp->next = NULL;
		if (head == NULL)
			head = temp;
		else
		{
			p = head;
			while (p->next != NULL)
				p = p->next;
			p->next = temp;
		}
	}
	return (head);
}

void	ft_env_tolist(t_tools *t)
{
	size_t	tab_len;

	tab_len = ft_2dlen (t->envp);
	t->env_list = ft_init_env_list (tab_len, t);
}
