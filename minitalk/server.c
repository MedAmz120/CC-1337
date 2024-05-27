/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:08:09 by moamzil           #+#    #+#             */
/*   Updated: 2023/01/12 16:48:45 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_previous_sender = 0;

void	handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;
	pid_t		sender_pid;

	sender_pid = info->si_pid;
	context = 0;
	if (sender_pid != g_previous_sender)
	{
		i = 0;
		bit = 0;
	}
	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
	g_previous_sender = sender_pid;
}

int	main(void)
{
	struct sigaction	action;
	pid_t				pi;

	pi = getpid();
	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pi, 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);
	while (1)
		pause();
	return (0);
}
