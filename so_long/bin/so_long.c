/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:33:19 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/14 18:54:33 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_map	m;

	if (ac == 2)
	{
		m.score = 0;
		reading(av[1], &m);
		m.total_score = 0;
		m.move_counter = 0;
		start_window(&m);
	}
	else
	{
		perror("Error\n:Too few arguments ...");
		exit(EXIT_FAILURE);
	}
	exit (0);
}
