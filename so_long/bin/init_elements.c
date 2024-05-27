/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:41:19 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/17 21:03:25 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_image_to_window(t_map *m, char e, int x, int y)
{
	void	*ptr;
	void	*win;

	ptr = m->mlx_ptr;
	win = m->mlx_win;
	mlx_put_image_to_window(ptr, win, m->backg, x * IW, y * IH);
	if (e == '1')
		mlx_put_image_to_window(ptr, win, m->wall, x * IW, y * IH);
	else if (e == 'C')
		mlx_put_image_to_window(ptr, win, m->coll, x * IW, y * IH);
	else if (e == 'E')
		mlx_put_image_to_window(ptr, win, m->exit, x * IW, y * IH);
	else if (e == 'P')
		mlx_put_image_to_window(ptr, win, m->player, x * IW, y * IH);
}

void	put_elements(t_map *m)
{
	size_t	y;
	size_t	x;
	char	**mapl;

	y = 0;
	mapl = m->all_lines;
	mlx_clear_window(m->mlx_ptr, m->mlx_win);
	while (y < m->tab_size)
	{
		x = 0;
		while (x < m->line_size - 1)
		{
			put_image_to_window(m, mapl[y][x], x, y);
			x++;
		}
		y++;
	}
}

int	init_element(t_map *m)
{
	int		y;
	int		x;

	m->backg = mlx_xpm_file_to_image(m->mlx_ptr,
			"textures/background.xpm", &x, &y);
	m->player = mlx_xpm_file_to_image(m->mlx_ptr,
			"textures/player.xpm", &x, &y);
	m->exit = mlx_xpm_file_to_image(m->mlx_ptr,
			"textures/exit.xpm", &x, &y);
	m->coll = mlx_xpm_file_to_image(m->mlx_ptr,
			"textures/collectible.xpm", &x, &y);
	m->wall = mlx_xpm_file_to_image(m->mlx_ptr,
			"textures/wall.xpm", &x, &y);
	if (!m->backg || !m->player || !m->exit
		|| !m->coll || !m->wall)
		return (0);
	put_elements(m);
	return (1);
}
