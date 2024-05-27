/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:10:17 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/07 22:47:49 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_tools	t;
	int		fd0; 
	int		fd1;

	fd0 = dup(STDIN_FILENO);
	fd1 = dup(STDOUT_FILENO);
	if (ac != 1 || av[1])
	{
		ft_putstr_fd("Error: The program does not accept arguments\n", 2);
		exit (EXIT_FAILURE);
	}
	ft_parsing (&t, envp, fd0, fd1);
	quit_program (&t, EXIT_SUCCESS);
	return (0);
}
