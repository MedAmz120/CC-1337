/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:58:42 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_cub_file(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 1] != 'b' || file[i - 2] != 'u'
		|| file[i - 3] != 'c' || file[i - 4] != '.')
	{
		perror ("Error\nInvalid map file\n");
		exit (EXIT_FAILURE);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_map	m;
	t_data	data;

	init_struct_pointers(&m);
	if (ac == 2)
	{
		check_cub_file(av[1]);
		read_file (open(av[1], 2), &m);
		start_game_window (&m, &data);
	}
	quit_program (SUCCESS, &m);
}
