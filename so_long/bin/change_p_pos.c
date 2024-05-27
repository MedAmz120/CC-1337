/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_p_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:16:49 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/02 12:33:38 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	score_counter(t_map *m, char elem)
{
	if (elem == 'C')
	{
		m->total_score += 10;
		if (m->total_score == m->score)
			ft_printf("Score reached Run to exit\n");
		else
			ft_printf("Collectible acquired. Total : %d.\n", m->total_score);
	}
}

void	move_p_down(t_map *m)
{
	score_counter(m, m->all_lines[m->player_y + 1][m->player_x]);
	m->all_lines[m->player_y][m->player_x] = '0';
	m->all_lines[m->player_y + 1][m->player_x] = 'P';
	move_counter(m);
}

void	move_p_up(t_map *m)
{
	score_counter(m, m->all_lines[m->player_y - 1][m->player_x]);
	m->all_lines[m->player_y][m->player_x] = '0';
	m->all_lines[m->player_y - 1][m->player_x] = 'P';
	move_counter(m);
}

void	move_p_right(t_map *m)
{
	score_counter(m, m->all_lines[m->player_y][m->player_x + 1]);
	m->all_lines[m->player_y][m->player_x] = '0';
	m->all_lines[m->player_y][m->player_x + 1] = 'P';
	move_counter(m);
}

void	move_p_left(t_map *m)
{
	score_counter(m, m->all_lines[m->player_y][m->player_x - 1]);
	m->all_lines[m->player_y][m->player_x] = '0';
	m->all_lines[m->player_y][m->player_x - 1] = 'P';
	move_counter(m);
}
