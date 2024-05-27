/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 04:00:38 by mrital-           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_twall(t_data *data, float x, float y)
{
	int	index;
	int	line_len;
	int	x_pix;
	int	y_pix;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (1);
	x_pix = (int)floor(x / TILE_SIZE);
	y_pix = (int)floor(y / TILE_SIZE);
	index = 0;
	while (data->map_dub[index])
		index++;
	if (y_pix >= index)
		return (1);
	line_len = ft_strlen(data->map_dub[y_pix]);
	if (x_pix >= line_len)
		return (1);
	if (data->map_dub[y_pix][x_pix] == '1')
		return (1);
	return (0);
}

static void	calculate_horz_intercepts(t_data *data, float ray_angle)
{
	t_map	*map;

	map = data->map;
	data->cast.y_inter = floor(map->y / TILE_SIZE) * TILE_SIZE;
	if (data->cast.is_down)
		data->cast.y_inter += TILE_SIZE;
	else
		data->cast.y_inter += 0;
	data->cast.x_inter = map->x + (data->cast.y_inter - map->y)
		/ tan(ray_angle);
}

static void	calculate_horz_xystep(t_data *data, float ray_angle)
{
	data->cast.y_step = TILE_SIZE;
	if (data->cast.is_up)
		data->cast.y_step *= -1;
	else
		data->cast.y_step *= 1;
	data->cast.x_step = TILE_SIZE / tan(ray_angle);
	if (data->cast.is_left && data->cast.x_step > 0)
		data->cast.x_step *= -1;
	else
		data->cast.x_step *= 1;
	if (data->cast.is_right && data->cast.x_step < 0)
		data->cast.x_step *= -1;
	else
		data->cast.x_step *= 1;
}

static void	search_horz_wall_hit(t_data *data)
{
	float	x_tocheck;
	float	y_tocheck;
	int		add_pix;

	if (data->cast.is_up)
		add_pix = -1;
	else
		add_pix = 0;
	while (true)
	{
		x_tocheck = data->cast.horznext_x;
		y_tocheck = data->cast.horznext_y + add_pix;
		if (is_twall(data, x_tocheck, y_tocheck))
		{
			data->cast.horzhit_x = data->cast.horznext_x;
			data->cast.horzhit_y = data->cast.horznext_y;
			data->cast.foundhorz_hit = 1;
			break ;
		}
		else
		{
			data->cast.horznext_x += data->cast.x_step;
			data->cast.horznext_y += data->cast.y_step;
		}
	}
}

void	horz_inter(t_data *data, float ray_angle)
{
	data->cast.is_down = ray_angle > 0 && ray_angle < M_PI;
	data->cast.is_up = !data->cast.is_down;
	data->cast.is_right = ray_angle < (M_PI / 2) || ray_angle > (3 * M_PI / 2);
	data->cast.is_left = !data->cast.is_right;
	calculate_horz_intercepts(data, ray_angle);
	calculate_horz_xystep(data, ray_angle);
	data->cast.horznext_x = data->cast.x_inter;
	data->cast.horznext_y = data->cast.y_inter;
	search_horz_wall_hit(data);
}
