/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:12:23 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/07 13:25:03 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_player_position(t_map *m)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < m->tab_size)
	{
		x = 0;
		while (x < m->line_size)
		{
			if (m->all_lines[y][x] == 'P')
			{
				m->player_x = x;
				m->player_y = y;
			}
			x++;
		}
		y++;
	}
}

int	check_exit(t_map *m, char elem)
{
	if (elem == 'E')
	{
		if (m->total_score == m->score)
		{
			ft_printf("You win\n");
			quit_game(m, 1);
		}
		else
		{
			ft_printf("You Have to reach Full score before exiting !\n");
			return (0);
		}
	}
	return (1);
}

int	check_elements(t_map *m, int pos)
{
	if (pos == 1)
		if ((m->all_lines[m->player_y + 1][m->player_x] != '1')
			&& ((check_exit(m, m->all_lines[m->player_y + 1][m->player_x]))))
			return (1);
	if (pos == 13)
		if ((m->all_lines[m->player_y - 1][m->player_x] != '1')
			&& ((check_exit(m, m->all_lines[m->player_y - 1][m->player_x]))))
			return (1);
	if (pos == 2)
		if ((m->all_lines[m->player_y][m->player_x + 1] != '1')
			&& ((check_exit(m, m->all_lines[m->player_y][m->player_x + 1]))))
			return (1);
	if (pos == 0)
		if ((m->all_lines[m->player_y][m->player_x - 1] != '1')
			&& ((check_exit(m, m->all_lines[m->player_y][m->player_x - 1]))))
			return (1);
	return (0);
}

void	move_player(int pos, t_map *m)
{
	get_player_position(m);
	if (pos == 1 && check_elements(m, 1))
		move_p_down(m);
	if (pos == 13 && check_elements(m, 13))
		move_p_up(m);
	if (pos == 2 && check_elements(m, 2))
		move_p_right(m);
	if (pos == 0 && check_elements(m, 0))
		move_p_left(m);
	put_elements(m);
}
