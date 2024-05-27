/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 05:26:30 by mrital-           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_textures(t_data *data)
{
	char	*str;

	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	str = ft_strtrim(data->map->no, "\n");
	data->no = mlx_load_png(str);
	free(str);
	str = ft_strtrim(data->map->so, "\n");
	data->so = mlx_load_png(str);
	free(str);
	str = ft_strtrim(data->map->ea, "\n");
	data->ea = mlx_load_png(str);
	free(str);
	str = ft_strtrim(data->map->we, "\n");
	data->we = mlx_load_png(str);
	free(str);
}

void	setup(t_data *data, t_map *m)
{
	data->width = ft_strlen(m->map[0]);
	data->height = ft_2dlen(m->map);
	data->x = WIDTH / 2;
	data->y = HEIGHT / 2;
	data->map = m;
	data->map_dub = m->map;
	init_textures(data);
	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", 0);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->ray = (t_ray *)malloc(sizeof(t_ray) * WIDTH);
}

void	start_game_window(t_map *m, t_data *data)
{
	setup(data, m);
	data->angle = init_angle(m);
	mlx_loop_hook(data->mlx, &hook, data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
