/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 05:25:43 by mrital-           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_sky_ground(t_data *data)
{
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < HEIGHT / 2)
	{
		i = 0;
		while (i <= WIDTH)
		{
			mlx_put_pixel(data->img, i++, y, ft_pxl(data->map->s_r,
					data->map->s_g, data->map->s_b, 255));
		}
		y++;
	}
	while (y < HEIGHT)
	{
		i = 0;
		while (i <= WIDTH)
		{
			mlx_put_pixel(data->img, i++, y, ft_pxl(data->map->g_r,
					data->map->g_g, data->map->g_b, 255));
		}
		y++;
	}
}

void	draw_game(t_data *data)
{
	data->direction = data->map->direction;
	draw_sky_ground(data);
	cast_all_rays(data);
	draw_game_textures(data);
}
