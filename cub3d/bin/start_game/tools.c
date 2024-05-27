/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 05:26:45 by mrital-           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_move_up(t_data *data)
{
	t_map	*map;

	map = data->map;
	map->x += cos(data->angle) * SPEED;
	map->y += sin(data->angle) * SPEED;
}

void	ft_move_down(t_data *data)
{
	t_map	*map;

	map = data->map;
	map->x += cos(data->angle) * (SPEED * -1);
	map->y += sin(data->angle) * (SPEED * -1);
}

void	ft_move_left(t_data *data)
{
	t_map	*map;

	map = data->map;
	map->x += cos(data->angle - M_PI / 2) * SPEED;
	map->y += sin(data->angle - M_PI / 2) * SPEED;
}

void	ft_move_right(t_data *data)
{
	t_map	*map;

	map = data->map;
	map->x += cos(data->angle + M_PI / 2) * SPEED;
	map->y += sin(data->angle + M_PI / 2) * SPEED;
}

void	hook(void *param)
{
	t_data	*mlx;
	t_map	*map;

	mlx = (t_data *)param;
	map = mlx->map;
	ft_norm(mlx, map);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_ESCAPE))
		quit_program(SUCCESS, map);
	else if (mlx_is_key_down(mlx->mlx, MLX_KEY_W))
		ft_move_up(mlx);
	else if (mlx_is_key_down(mlx->mlx, MLX_KEY_S))
		ft_move_down(mlx);
	else if (mlx_is_key_down(mlx->mlx, MLX_KEY_D))
		ft_move_right(mlx);
	else if (mlx_is_key_down(mlx->mlx, MLX_KEY_A))
		ft_move_left(mlx);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_RIGHT))
		mlx->angle += 0.1;
	else if (mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT))
		mlx->angle -= 0.1;
	setup_angle(&mlx->angle);
	draw(mlx, map);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
}
