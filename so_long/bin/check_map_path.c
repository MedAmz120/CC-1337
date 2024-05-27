/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:10:24 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/04 17:52:01 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill_empty(t_map *m, size_t x, size_t y)
{
	m->l_cpe[x][y] = '1';
	if (m->l_cpe[x - 1][y] != '1')
		fill_empty(m, x - 1, y);
	if (m->l_cpe[x][y - 1] != '1')
		fill_empty(m, x, y - 1);
	if (m->l_cpe[x + 1][y] != '1')
		fill_empty(m, x + 1, y);
	if (m->l_cpe[x][y + 1] != '1')
		fill_empty(m, x, y + 1);
}

int	check(t_map *m, size_t x, size_t y)
{
	size_t	i;

	i = 0;
	fill_empty(m, x, y);
	while (i < m->tab_size)
	{
		y = 0;
		while (y < m->line_size)
		{
			if (m->l_cpe[i][y] == 'E' || m->l_cpe[i][y] == 'C')
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	check_valid_path(t_map *m)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < m->tab_size)
	{
		j = 0;
		while (j < m->line_size)
		{
			if (m->all_lines[i][j] == 'P')
				break ;
			j++;
		}
		if (m->all_lines[i][j] == 'P')
			break ;
		i++;
	}
	if (!check(m, i, j))
	{
		perror("Error\n:Invalid path in Map Quitting ...\n");
		return (0);
	}
	return (1);
}
