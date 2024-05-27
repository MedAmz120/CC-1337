/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:41:01 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/07 13:41:06 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_line_lenght(char *str, t_map *m)
{
	if (ft_strlen(str) != m->line_size)
		return (0);
	return (1);
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'C' && str[i] != 'E' && str[i] != 'P'
			&& str[i] != '1' && str[i] != '0' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	must_contain(t_map *m)
{
	int			i;
	int			y;
	static int	p;
	static int	c;
	static int	e;

	i = 0;
	while (m->map_lines[i])
	{
		y = 0;
		while (m->map_lines[i][y])
		{
			if (m->map_lines[i][y] == 'P')
				p++;
			if (m->map_lines[i][y] == 'C')
				c++;
			if (m->map_lines[i][y] == 'E')
				e++;
			y++;
		}
		i++;
	}
	if (p != 1 || c == 0 || e != 1)
		return (0);
	return (1);
}

int	check_wall_rect(t_map *m)
{
	int		i;
	int		x;
	size_t	y;

	i = -1;
	while (m->map_lines[0][++i])
		if (m->map_lines[0][i] != '1' && m->map_lines[0][i] != '\n')
			return (0);
	y = table_size_counter(m) - 1;
	i = -1;
	while (m->map_lines[y][++i])
		if (m->map_lines[y][i] != '1' && m->map_lines[y][i] != '\n')
			return (0);
	i = -1;
	while (m->map_lines[++i])
	{
		x = -1;
		while (m->map_lines[i][++x])
			if (m->map_lines[i][0] != '1'
			|| m->map_lines[i][m->line_size - 2] != '1')
				return (0);
	}
	if (m->line_size == m->tab_size)
		return (0);
	return (1);
}

int	check_map(t_map *m)
{
	int	i;

	i = 0;
	while (m->map_lines[i])
	{
		if (!check_line(m->map_lines[i])
			|| !check_line_lenght(m->map_lines[i], m))
			return (0);
		i++;
	}
	if (!must_contain(m))
		return (0);
	if (!check_wall_rect(m))
		return (0);
	return (1);
}
