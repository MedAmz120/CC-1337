/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:43:11 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/07 13:26:07 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	quit_game(t_map *m, int s)
{
	int	i;

	if (m->player)
		mlx_destroy_image(m->mlx_ptr, m->player);
	if (m->backg)
		mlx_destroy_image(m->mlx_ptr, m->backg);
	if (m->exit)
		mlx_destroy_image(m->mlx_ptr, m->exit);
	if (m->coll)
		mlx_destroy_image(m->mlx_ptr, m->coll);
	if (m->wall)
		mlx_destroy_image(m->mlx_ptr, m->wall);
	if (m->mlx_ptr || m->mlx_win)
		mlx_destroy_window(m->mlx_ptr, m->mlx_win);
	i = -1;
	if (s != 0)
	{
		while (m->all_lines[++i])
			free(m->all_lines[i]);
		free(m->all_lines);
	}
	if (m->mlx_ptr)
		free(m->mlx_ptr);
	exit (0);
}

void	start_window(t_map *m)
{
	int		w;

	w = (m->line_size - 1);
	m->mlx_ptr = mlx_init();
	m->mlx_win = mlx_new_window(m->mlx_ptr, w * IW, m->tab_size * IH, "Solong");
	if (!m->mlx_ptr || !m->mlx_win)
		quit_game(m, 1);
	if (!init_element(m))
	{
		perror("Error\n:Invalid XPM Files\n");
		quit_game(m, 1);
	}
	mlx_key_hook(m->mlx_win, key_press, m);
	mlx_hook(m->mlx_win, 17, 0, quit_game, m);
	mlx_loop(m->mlx_ptr);
}
