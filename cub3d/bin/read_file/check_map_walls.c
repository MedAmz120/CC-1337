/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:46:16 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_map_walls(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (m->map[0][++j])
		if (m->map[0][j] != '1')
			quit_program(INVALID_MAP, m);
	while (m->map[i])
	{
		if (m->map[i][0] != '1')
			quit_program (INVALID_MAP, m);
		if (m->map[i][ft_strlen(m->map[i]) - 1] != '1')
			quit_program (INVALID_MAP, m);
		i++;
	}
	i -= 1;
	j = -1;
	while (m->map[i][++j])
		if (m->map[i][j] != '1')
			quit_program(INVALID_MAP, m);
}
