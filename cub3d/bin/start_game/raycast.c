/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 04:06:31 by mrital-           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	dist_two_points(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

static void	check_calculate_dist(t_data *data, float h_d, float v_d, int i)
{
	if (v_d <= h_d)
	{
		data->ray[i].distance = v_d;
		data->ray[i].wallhit_x = data->cast.verthit_x;
		data->ray[i].wallhit_y = data->cast.verthit_y;
		data->ray[i].hit_vertical = 1;
	}
	else
	{
		data->ray[i].distance = h_d;
		data->ray[i].wallhit_x = data->cast.horzhit_x;
		data->ray[i].wallhit_y = data->cast.horzhit_y;
		data->ray[i].hit_vertical = 0;
	}
}

void	calculate_hit(t_data *data, int i)
{
	float	horz_hit_dist;
	float	vert_hit_dist;
	t_map	*map;

	map = data->map;
	if (data->cast.foundhorz_hit == 1)
		horz_hit_dist = dist_two_points(map->x, map->y, data->cast.horzhit_x,
				data->cast.horzhit_y);
	else
		horz_hit_dist = INT_MAX;
	if (data->cast.foundvert_hit == 1)
		vert_hit_dist = dist_two_points(map->x, map->y, data->cast.verthit_x,
				data->cast.verthit_y);
	else
		vert_hit_dist = INT_MAX;
	check_calculate_dist(data, horz_hit_dist, vert_hit_dist, i);
}

void	cast_ray(t_data *data, int i)
{
	setup_angle(&data->ray->ray_angle);
	horz_inter(data, data->ray->ray_angle);
	vert_inter(data, data->ray->ray_angle);
	calculate_hit(data, i);
}

void	cast_all_rays(t_data *data)
{
	int	i;

	i = 0;
	data->ray->ray_angle = data->angle - (FOV_ANGLE / 2);
	while (i < WIDTH)
	{
		data->ray[i].ray_angle = data->ray->ray_angle;
		cast_ray(data, i);
		data->ray->ray_angle += FOV_ANGLE / WIDTH;
		i++;
	}
	data->ray[0].ray_angle = data->angle - (FOV_ANGLE / 2);
}
