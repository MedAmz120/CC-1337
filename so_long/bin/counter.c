/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:17:13 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/13 11:07:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_counter(t_map *m)
{
	m->move_counter++;
	ft_printf("number of movements : %d\n", m->move_counter);
}

size_t	table_size_counter(t_map *m)
{
	m->tab_size = 0;
	while (m->map_lines[m->tab_size] != NULL)
		m->tab_size++;
	return (m->tab_size);
}

int	word_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

int	ft_word_cnt(char *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if ((i == 0 && str[i] != c) || (str[i] == c && str[i + 1] != '\0'
				&& str[i + 1] != c))
			cnt++;
		i++;
	}
	return (cnt);
}

char	**copie_map(t_map *m)
{
	size_t	i;
	char	**cp;

	i = 0;
	cp = (char **)malloc(sizeof(char *) * m->tab_size + 1);
	if (!cp)
		return (0);
	while (i < m->tab_size)
	{
		cp[i] = malloc(sizeof(char) * m->line_size + 1);
		if (!cp[i])
			quit_game (m, 1);
		ft_strlcpy(cp[i], m->all_lines[i], m->line_size);
		i++;
	}
	cp[i] = 0;
	return (cp);
}
