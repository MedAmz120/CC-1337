/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:59:06 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_directions(char **lines, t_map *m)
{
	int		i;
	int		j;

	i = -1;
	while (lines[++i])
	{
		j = 0;
		if (lines[i][j] != '\n')
		{
			while (lines[i][j] == ' ' && lines[i][j])
				j++;
			if (lines[i][j] == 'N' && lines[i][j + 1] == 'O')
				m->no = ft_strdup_no_newlines(lines[i]);
			else if (lines[i][j] == 'S' && lines[i][j + 1] == 'O')
				m->so = ft_strdup_no_newlines(lines[i]);
			else if (lines[i][j] == 'W' && lines[i][j + 1] == 'E')
				m->we = ft_strdup_no_newlines(lines[i]);
			else if (lines[i][j] == 'E' && lines[i][j + 1] == 'A')
				m->ea = ft_strdup_no_newlines(lines[i]);
			else if (lines[i][j] == 'F' && lines[i][j + 1] == SPACE)
				m->f = ft_strdup_no_newlines(lines[i]);
			else if (lines[i][j] == 'C' && lines[i][j + 1] == SPACE)
				m->c = ft_strdup_no_newlines(lines[i]);
		}
	}
}

void	check_tabs(char **lines, t_map *m)
{
	int	i;
	int	y;

	i = 0;
	while (lines[i])
	{
		y = -1;
		while (lines[i][++y])
			if (lines[i][y] == '\t')
				quit_program (INVALID_MAP, m);
		i++;
	}
}

void	filter_lines(char **lines, t_map *m)
{
	check_tabs(lines, m);
	set_directions (lines, m);
	clean_directions (m);
	read_map_lines (lines, m);
	check_inv_map_elem(m);
}

void	init_player_direction(char **lines, t_map *m)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'W' || lines[i][j] == 'E'
				|| lines[i][j] == 'S' || lines[i][j] == 'N')
			{
				m->direction = lines[i][j];
				counter++;
				if (counter > 1)
					quit_program (INVALID_MAP, m);
			}
			j++;
		}
		i++;
	}
}

void	read_file(int fd, t_map *m)
{
	char	**lines;
	char	**tmp2d;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	lines = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (!tmp[0] || tmp[0] == '\n')
		{
			free(tmp);
			tmp = NULL;
			continue ;
		}
		tmp2d = realloc_2d(lines, tmp);
		lines = tmp2d;
		if (!lines[i++][0])
			break ;
	}
	read_file_part2(lines, m);
}
