/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:31:31 by moamzil           #+#    #+#             */
/*   Updated: 2023/10/05 19:42:58 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_thinking(t_per *philo)
{
	time_t	t_stmp;

	t_stmp = get_timestamp_ms() - philo->global->run_time;
	printf_message (philo, t_stmp, "is thinking");
}

void	take_fork(t_per *philo)
{
	time_t	t_stmp;
	int		left_fork;
	int		right_fork;

	left_fork = ((philo->id - 1) + 1) % (philo->global->n_o_p);
	right_fork = philo->id - 1;
	pthread_mutex_lock(&philo->global->mutex[left_fork]);
	t_stmp = get_timestamp_ms() - philo->global->run_time;
	printf_message (philo, t_stmp, "has taken a fork");
	if (philo->global->n_o_p == 1)
	{
		my_usleep (philo->global->t_t_d);
		return ;
	}
	pthread_mutex_lock(&philo->global->mutex[right_fork]);
	t_stmp = get_timestamp_ms() - philo->global->run_time;
	printf_message (philo, t_stmp, "has taken a fork");
}

void	start_eating(t_per *philo)
{
	time_t	t_stmp;
	int		left_fork;
	int		right_fork;

	left_fork = ((philo->id - 1) + 1) % (philo->global->n_o_p);
	right_fork = philo->id - 1;
	t_stmp = get_timestamp_ms() - philo->global->run_time;
	printf_message (philo, t_stmp, "is eating");
	my_usleep(philo->global->t_t_e);
	pthread_mutex_lock (&philo->global->global_m);
	philo->last_time_eat = get_timestamp_ms();
	philo->eat_c++;
	pthread_mutex_unlock (&philo->global->global_m);
	pthread_mutex_unlock(&philo->global->mutex[right_fork]);
	pthread_mutex_unlock(&philo->global->mutex[left_fork]);
}

void	start_sleeping(t_per *philo)
{
	time_t	t_stmp;

	t_stmp = get_timestamp_ms() - philo->global->run_time;
	my_usleep(philo->global->t_t_s);
	printf_message (philo, t_stmp, "is sleeping");
}

void	*philo_actions(void *arg)
{
	t_per	*philo;

	philo = (t_per *)arg;
	pthread_mutex_lock(&philo->global->global_m);
	philo->global->should_break = 0;
	pthread_mutex_unlock(&philo->global->global_m);
	while (philo->global->state != DEAD_S)
	{
		if (philo->global->should_break == -1)
			break ;
		start_thinking(philo);
		take_fork(philo);
		start_eating(philo);
		start_sleeping(philo);
	}
	return (NULL);
}
