/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 05:26:37 by mrital-           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	generate_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

float	angle_adjast(float angle, char sign)
{
	if (angle <= 0)
		angle += M_PI * 2;
	if (sign == '-')
		angle -= M_PI / 180;
	if (sign == '+')
		angle += M_PI / 180;
	if (angle > M_PI * 2)
		angle -= M_PI * 2;
	return (angle);
}

void	setup_angle(float *angle)
{
	*angle = remainder(*angle, 2 * M_PI);
	if (*angle < 0)
		*angle = (2 * M_PI) + *angle;
}

int	check_wall(t_data *data)
{
	t_map	*map;

	map = data->map;
	if ((data->map_dub[(int)(map->y / TILE_SIZE)]
		[(int)(data->t_x / TILE_SIZE)] == '1' ||
			data->map_dub[(int)(data->t_y / TILE_SIZE)]
			[(int)(map->x / TILE_SIZE)] == '1' ||
			data->map_dub[(int)(data->t_y / TILE_SIZE)]
			[(int)(data->t_x / TILE_SIZE)] == '1'))
		return (1);
	return (0);
}

float	init_angle(t_map *map)
{
	if (map->direction == 'N')
		return (3 * M_PI / 2);
	else if (map->direction == 'S')
		return (M_PI_2);
	else if (map->direction == 'W')
		return (M_PI);
	else if (map->direction == 'E')
		return (0);
	return (0);
}
