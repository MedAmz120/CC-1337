/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_part2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:48:15 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	read_file_part2(char **lines, t_map *m)
{
	init_struct_pointers(m);
	filter_lines(lines, m);
	check_paths (m);
	check_rgbs (m);
	init_player_direction(m->map, m);
	check_map_walls(m);
}
