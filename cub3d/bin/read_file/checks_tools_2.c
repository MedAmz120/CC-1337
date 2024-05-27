/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_tools_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:59:30 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_paths(t_map *m)
{
	int	fd;

	fd = open (m->no, 2);
	if (fd == -1)
		quit_program (INVALID_PATH, m);
	fd = open (m->so, 2);
	if (fd == -1)
		quit_program (INVALID_PATH, m);
	fd = open (m->we, 2);
	if (fd == -1)
		quit_program (INVALID_PATH, m);
	fd = open (m->ea, 2);
	if (fd == -1)
		quit_program (INVALID_PATH, m);
}
