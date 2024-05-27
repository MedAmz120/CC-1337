/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:58:57 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_start_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	get_map_start_line(char **lines)
{
	int	i;
	int	j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j] == SPACE && lines[i][j])
			j++;
		if ((lines[i][0] == '0' || lines[i][0] == '1') 
			&& check_start_line(lines[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	set_lines_to_map(int s, char **lines, t_map *m)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = 0;
	while (lines[s])
	{
		if (lines[s][0] == '0' || lines[s][0] == '1')
		{
			tmp = remove_char(lines[s], SPACE);
			m->map = realloc_2d(m->map, tmp);
		}
		s++;
	}
}

int	get_player_position(t_map *m)
{
	int	x;
	int	y;
	int	found;

	y = 0;
	found = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'N' || m->map[y][x] == 'S'
				|| m->map[y][x] == 'W' || m->map[y][x] == 'E')
			{
				m->x = (x * TILE_SIZE) + (TILE_SIZE / 2);
				m->y = (y * TILE_SIZE) + (TILE_SIZE / 2);
				found++;
			}
			x++;
		}
		y++;
	}
	return (found);
}

void	read_map_lines(char **lines, t_map *m)
{
	int	s;
	int	player;

	s = get_map_start_line(lines);
	if (s == -1)
		quit_program (MISSING_MAP, m);
	set_lines_to_map (s, lines, m);
	player = get_player_position(m);
	if (player == 0 || player > 1)
		quit_program (INVALID_MAP, m);
}
