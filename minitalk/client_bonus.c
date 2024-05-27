/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:38:32 by moamzil           #+#    #+#             */
/*   Updated: 2023/01/11 19:43:24 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"

void	send_signal(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!(c & (1 << i)))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i++;
	}
}

void	handler(int sig)
{
	if (sig)
		ft_putstr_fd("Received !", 1);
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (ac != 3)
	{
		ft_putstr_fd("./client: illegal option -- -\n", 1);
		ft_putstr_fd("usage: ./client [PID] [BYTES TO SEND]", 1);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid == 0)
		return (0);
	signal(SIGUSR1, handler);
	while (av[2][i] != '\0')
	{
		send_signal(pid, av[2][i]);
		i++;
	}
	send_signal(pid, '\0');
	return (0);
}
