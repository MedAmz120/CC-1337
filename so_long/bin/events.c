/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:19:58 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/07 13:24:24 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_press(int key, t_map *m)
{
	if (key == 13 || key == 126)
		move_player(13, m);
	if (key == 0 || key == 123)
		move_player(0, m);
	if (key == 1 || key == 125)
		move_player(1, m);
	if (key == 2 || key == 124)
		move_player(2, m);
	if (key == 53)
		quit_game(m, 1);
	return (1);
}
