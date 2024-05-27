/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:58:42 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_struct_rgbs(t_map *m, char *str, int index)
{
	int	i;
	int	pos;

	i = 0;
	pos = 1;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (index == 1)
				init_variables_sky(m, str, pos, i);
			if (index == 2)
				init_variables_ground(m, str, pos, i);
			while (str[i] && str[i] != ',')
				i++;
			pos++;
		}
		else
			i++;
	}
}

char	*remove_spaces_id(char *str, t_map *m)
{
	int		i;
	char	*res;

	i = 2;
	if (!str)
		quit_program (MISSING_IDENTIFIER, m);
	while (str[i] == SPACE && str[i])
		i++;
	res = ft_substr(str, i, ft_strlen_from(str, i));
	free (str);
	str = 0;
	if (res[0] == '\0')
		quit_program (MISSING_IDENTIFIER, m);
	return (res);
}

void	clean_directions_2(t_map *m)
{
	char	*tmp;

	tmp = NULL;
	tmp = remove_spaces_id(m->ea, m);
	if (!tmp)
		quit_program(MISSING_IDENTIFIER, m);
	m->ea = ft_strdup(tmp);
	free (tmp);
	tmp = remove_spaces_id(m->f, m);
	if (!tmp)
		quit_program(MISSING_IDENTIFIER, m);
	m->f = ft_strdup(tmp);
	free (tmp);
	tmp = remove_spaces_id(m->c, m);
	if (!tmp)
		quit_program(MISSING_IDENTIFIER, m);
	m->c = ft_strdup(tmp);
	free (tmp);
}

void	clean_directions(t_map *m)
{
	char	*tmp;

	tmp = NULL;
	tmp = remove_spaces_id(m->no, m);
	if (!tmp)
		quit_program(MISSING_IDENTIFIER, m);
	m->no = ft_strdup(tmp);
	free (tmp);
	tmp = remove_spaces_id(m->so, m);
	if (!tmp)
		quit_program(MISSING_IDENTIFIER, m);
	m->so = ft_strdup(tmp);
	free (tmp);
	tmp = remove_spaces_id(m->we, m);
	if (!tmp)
		quit_program(MISSING_IDENTIFIER, m);
	m->we = ft_strdup(tmp);
	free (tmp);
	clean_directions_2(m);
}

void	check_inv_map_elem(t_map *m)
{
	int	i;
	int	y;

	i = 0;
	while (m->map[i])
	{
		y = 0;
		while (m->map[i][y])
		{
			if (!check_elem(m->map[i][y]))
				quit_program (INVALID_MAP, m);
			y++;
		}
		i++;
	}
}
