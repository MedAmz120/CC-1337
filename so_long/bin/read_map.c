/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:40:55 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/17 18:57:43 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	reading(char *file_name, t_map *m)
{
	int		i;
	char	*tmp;

	i = -1;
	read_map(file_name, m);
	tmp = put_all_in_one(m->map_lines, m);
	m->all_lines = so_long_split(tmp, '\n');
	free(tmp);
	m->l_cpe = copie_map(m);
	while (m->map_lines[++i])
		free(m->map_lines[i]);
	free(m->map_lines);
	if (!(m->all_lines) || !(m->l_cpe) || !(check_valid_path(m)))
		quit_game (m, 1);
	i = -1;
	while (m->l_cpe[++i])
		free(m->l_cpe[i]);
	free(m->l_cpe);
}

int	check_ext(char *file)
{
	size_t	len;

	len = ft_strlen(file) - 1;
	if (file[len] != 'r')
		return (0);
	else if (file[len - 1] != 'e')
		return (0);
	else if (file[len - 2] != 'b')
		return (0);
	else if (file[len - 3] != '.')
		return (0);
	else
		return (1);
}

int	check_file(char *file, t_map *m)
{
	m->fd = open(file, O_RDONLY);
	if ((m->fd < 0) || !(check_ext(file)))
		return (0);
	return (1);
}

void	get_lines(t_map *m)
{
	int	i;

	i = 1;
	m->map_lines = malloc(sizeof(char *) * MAX_TAB);
	if (!m->map_lines)
		exit(EXIT_FAILURE);
	m->map_lines[0] = get_next_line(m->fd);
	m->line_size = ft_strlen(m->map_lines[0]);
	while (1)
	{
		m->map_lines[i] = get_next_line(m->fd);
		if (!m->map_lines[i])
			break ;
		i++;
	}
	m->map_lines[i] = 0;
	if (!check_map(m))
	{
		perror("Error\n:Invalid Map Fix issue.");
		quit_game(m, 0);
	}
}

void	read_map(char *file, t_map *m)
{
	if (!check_file(file, m))
	{
		perror("Error\n:Invalid map File or no such file.");
		exit(EXIT_FAILURE);
	}
	get_lines(m);
}
