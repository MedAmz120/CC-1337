/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:48:07 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_texture(t_data *data, int i)
{
	int	start;

	start = data->wall_top;
	data->wall_top = data->wall_top * (data->wall_top > 0);
	if (data->wall_bottom > HEIGHT)
		data->wall_bottom = HEIGHT;
	while (data->wall_top < data->wall_bottom)
	{
		set_y_texture_coord(data, start);
		mlx_put_pixel(data->img, i, data->wall_top,
			init_texture_c(data->cast.x_text, data->cast.y_text,
				data->cast.texture));
		if (data->cast.y_text < 0)
			data->cast.y_text = 0;
		if (data->cast.y_text >= data->cast.texture->height)
			data->cast.y_text = data->cast.texture->height - 1;
		data->wall_top++;
	}
}
/*
	distance from the player to the wall using trigonometry 
	This correction  accounts for the player's viewing angle, ensuring 
	that walls are rendered correctly with perspective.
	correction needed when we are more closer and if we turn
	the player head the wall  height increase
*/
/*
	(HEIGHT / 2) = 300 pixels (vertical center of the screen).
	(data->wall_h / 2) = 100 pixels (half of the wall height).
	data->wall_top = 300 - 100 = 200 pixels.
*/

void	draw_game_textures(t_data *data)
{
	int		i;
	float	corrected_dist;

	i = 0;
	while (i < WIDTH)
	{
		corrected_dist = data->ray[i].distance * cos(data->ray[i].ray_angle
				- data->angle);
		data->wall_h = 13000 / corrected_dist;
		data->wall_top = (HEIGHT / 2) - (data->wall_h / 2);
		data->wall_bottom = (HEIGHT / 2) + (data->wall_h / 2);
		set_textures(data, i);
		set_x_texture_coord(data, i, data->cast.texture);
		draw_texture(data, i);
		i++;
	}
}

void	draw(t_data *mlx, t_map *map)
{
	if (check_wall(mlx))
	{
		map->x = mlx->t_x;
		map->y = mlx->t_y;
	}
	draw_game(mlx);
}

void	ft_norm(t_data *mlx, t_map *map)
{
	mlx_delete_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->t_x = map->x;
	mlx->t_y = map->y;
}
