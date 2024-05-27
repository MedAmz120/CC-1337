/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:56:17 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_x_texture_coord(t_data *data, int i, mlx_texture_t *texture)
{
	float	hit_coord;

	if (data->ray[i].hit_vertical == 1)
		hit_coord = data->ray[i].wallhit_y;
	else
		hit_coord = data->ray[i].wallhit_x;
	if (hit_coord >= 0 && hit_coord < WIDTH)
		data->cast.x_text = fmod(hit_coord, TILE_SIZE) * (texture->width
				/ TILE_SIZE);
}

void	set_y_texture_coord(t_data *data, int start)
{
	data->cast.y_text = ((float)data->cast.texture->height / data->wall_h)
		* (data->wall_top - start);
}

int	ft_pxl(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	set_textures(t_data *data, int i)
{
	if (data->ray[i].hit_vertical != 1 && data->ray[i].ray_angle >= 0
		&& data->ray[i].ray_angle < M_PI)
		data->cast.texture = data->no;
	else if (data->ray[i].hit_vertical != 1 && data->ray[i].ray_angle >= M_PI
		&& data->ray[i].ray_angle < 2 * M_PI)
		data->cast.texture = data->so;
	else if (data->ray[i].hit_vertical == 1 && data->ray[i].ray_angle >= M_PI
		/ 2 && data->ray[i].ray_angle < 3 * M_PI / 2)
		data->cast.texture = data->we;
	else
		data->cast.texture = data->ea;
}

int	init_texture_c(float x, float y, mlx_texture_t *texture)
{
	int	pixel_index;
	int	r;
	int	g;
	int	b;
	int	a;

	if (x < 0 || y < 0 || (uint32_t)x >= texture->width
		|| (uint32_t)y >= texture->height)
		return (ft_pxl(0, 0, 0, 255));
	pixel_index = ((int)y * (int)texture->width + (int)x)
		* (int)texture->bytes_per_pixel;
	r = texture->pixels[pixel_index + 0];
	g = texture->pixels[pixel_index + 1];
	b = texture->pixels[pixel_index + 2];
	a = texture->pixels[pixel_index + 3];
	return (ft_pxl(r, g, b, a));
}
