/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:24:20 by moamzil           #+#    #+#             */
/*   Updated: 2023/10/05 20:06:20 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_message(t_per *philo, time_t t, char *str)
{
	pthread_mutex_lock (&philo->global->global_m);
	if (philo->global->state != DEAD_S)
		printf("%ld %d %s\n", t, philo->id, str);
	pthread_mutex_unlock (&philo->global->global_m);
}

time_t	get_timestamp_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	my_usleep(int sleep_time)
{
	time_t	now;

	now = get_timestamp_ms();
	while (get_timestamp_ms() - now < sleep_time)
		usleep(85);
}

int	check_philo_state(t_per *philo)
{
	time_t	actual_time;
	time_t	time_since_last_eat;

	actual_time = get_timestamp_ms();
	time_since_last_eat = actual_time - philo->last_time_eat;
	if (time_since_last_eat >= philo->t_t_d)
		return (0);
	return (1);
}

void	*check_threads(void *arg)
{
	static int		i;
	time_t			t;
	t_per			*philo;

	philo = (t_per *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->global->global_m);
		if (!check_philo_state(&philo[i]))
		{
			if (philo->global->n_m_e == -1 || philo->global->n_o_p == 1)
			{
				t = get_timestamp_ms() - philo->run_time;
				printf("%lu %d died\n", t, philo[i].id);
				philo->global->state = DEAD_S;
				pthread_mutex_unlock(&philo->global->global_m);
				return (NULL);
			}
		}
		pthread_mutex_unlock(&philo->global->global_m);
		if (check_nme (philo))
			break ;
		i = (i + 1) % philo->global->n_o_p;
	}
	return (NULL);
}
