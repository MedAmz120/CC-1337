/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 04:00:41 by mrital-           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	calculate_vert_intercepts(t_data *data, float ray_angle)
{
	t_map	*map;

	map = data->map;
	data->cast.x_inter = floor(map->x / TILE_SIZE) * TILE_SIZE;
	if (data->cast.is_right)
		data->cast.x_inter += TILE_SIZE;
	else
		data->cast.x_inter += 0;
	data->cast.y_inter = map->y + (data->cast.x_inter - map->x)
		* tan(ray_angle);
}

static void	calculate_vert_xystep(t_data *data, float ray_angle)
{
	data->cast.x_step = TILE_SIZE;
	if (data->cast.is_left)
		data->cast.x_step *= -1;
	else
		data->cast.x_step *= 1;
	data->cast.y_step = TILE_SIZE * tan(ray_angle);
	if (data->cast.is_up && data->cast.y_step > 0)
		data->cast.y_step *= -1;
	else
		data->cast.y_step *= 1;
	if (data->cast.is_down && data->cast.y_step < 0)
		data->cast.y_step *= -1;
	else
		data->cast.y_step *= 1;
}

static void	search_vert_wall_hit(t_data *data)
{
	float	x_tocheck;
	float	y_tocheck;
	int		add_pix;

	if (data->cast.is_left)
		add_pix = -1;
	else
		add_pix = 0;
	while (true)
	{
		x_tocheck = data->cast.vertnext_x + add_pix;
		y_tocheck = data->cast.vertnext_y;
		if (is_twall(data, x_tocheck, y_tocheck))
		{
			data->cast.verthit_x = data->cast.vertnext_x;
			data->cast.verthit_y = data->cast.vertnext_y;
			data->cast.foundvert_hit = 1;
			break ;
		}
		else
		{
			data->cast.vertnext_x += data->cast.x_step;
			data->cast.vertnext_y += data->cast.y_step;
		}
	}
}

void	vert_inter(t_data *data, float ray_angle)
{
	data->cast.is_down = ray_angle > 0 && ray_angle < M_PI;
	data->cast.is_up = !data->cast.is_down;
	data->cast.is_right = ray_angle < (M_PI / 2) || ray_angle > (3 * M_PI / 2);
	data->cast.is_left = !data->cast.is_right;
	calculate_vert_intercepts(data, ray_angle);
	calculate_vert_xystep(data, ray_angle);
	data->cast.vertnext_x = data->cast.x_inter;
	data->cast.vertnext_y = data->cast.y_inter;
	search_vert_wall_hit(data);
}
