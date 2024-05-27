/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:58:24 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_struct_pointers(t_map *m)
{
	m->ea = NULL;
	m->we = NULL;
	m->no = NULL;
	m->so = NULL;
	m->map = NULL;
	m->mlx_ptr = NULL;
	m->mlx_win = NULL;
}

void	free_2darr(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		if (tab[i])
			free (tab[i]);
		tab[i] = NULL;
		i++;
	}
	if (tab)
		free (tab);
	tab = NULL;
}

void	free_struct_pointers(t_map *m)
{
	if (ft_strlen(m->no) > 0)
		free (m->no);
	if (ft_strlen(m->so) > 0)
		free (m->so);
	if (ft_strlen(m->we) > 0)
		free (m->we);
	if (ft_strlen(m->ea) > 0)
		free (m->ea);
	if (m->map)
		free_2darr(m->map);
}

void	quit_program(int errid, t_map *m)
{
	free_struct_pointers(m);
	if (errid == MISSING_IDENTIFIER)
		perror ("Error\n:Missing identifier please fix .cub file\n");
	if (errid == MISSING_MAP)
		perror ("Error\n:Missing Map elements please fix .cub file\n");
	if (errid == INVALID_MAP)
		perror ("Error\n:Invalid Map please fix .cub file\n");
	if (errid == WINDOW_ERROR)
		perror ("Error\n:Unable to intialze window\n");
	if (errid == INVALID_PATH)
		perror ("Error\n:Invalid PATH in elements please fix .cub file\n");
	if (errid == INVALID_RGB)
		perror ("Error\n:Invalid RGB in elements please fix .cub file\n");
	if (errid == SUCCESS)
		exit (EXIT_SUCCESS);
	exit (EXIT_FAILURE);
}
