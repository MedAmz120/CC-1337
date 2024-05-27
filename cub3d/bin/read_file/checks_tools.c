/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:58:36 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_elem(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E');
}

void	check_rgbs(t_map *m)
{
	if (count_commas(m->f) == -1 || check_ranges(m->f) == -1)
		quit_program (INVALID_RGB, m);
	if (count_commas(m->c) == -1 || check_ranges(m->c) == -1)
		quit_program (INVALID_RGB, m);
	init_struct_rgbs(m, m->c, 1);
	init_struct_rgbs(m, m->f, 2);
}

size_t	num_size(char *str, int start)
{
	size_t	counter;

	counter = 0;
	while (str[start] && (str[start] >= '0' && str[start] <= '9'))
	{
		counter++;
		start++;
	}
	return (counter);
}

void	init_variables_ground(t_map *m, char *str, int pos, int i)
{
	char	*tmp;

	tmp = ft_substr(str, i, num_size(str, i));
	if (pos == 1)
		m->g_r = ft_atoi(tmp);
	if (pos == 2)
		m->g_g = ft_atoi(tmp);
	if (pos == 3)
		m->g_b = ft_atoi(tmp);
	free (tmp);
}

void	init_variables_sky(t_map *m, char *str, int pos, int i)
{
	char	*tmp;

	tmp = ft_substr(str, i, num_size(str, i));
	if (pos == 1)
		m->s_r = ft_atoi(tmp);
	if (pos == 2)
		m->s_g = ft_atoi(tmp);
	if (pos == 3)
		m->s_b = ft_atoi(tmp);
	free (tmp);
}
