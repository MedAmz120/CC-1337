/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:05:14 by moamzil           #+#    #+#             */
/*   Updated: 2023/10/05 20:22:49 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_phi *p, t_per *philo)
{
	int	i;

	i = -1;
	p->mutex = malloc(sizeof(pthread_mutex_t) * p->n_o_f);
	if (!p->mutex)
		return (0);
	p->forks_sta = 1;
	while (++i < p->n_o_f)
	{
		if (pthread_mutex_init(&p->mutex[i], NULL) != 0)
		{
			printf("Error\n Failed to init mutex id [%d] ", i);
			free_resources (philo, p);
			return (0);
		}
	}
	return (1);
}

int	init_philos(t_per *philo)
{
	int			i;
	pthread_t	monitory;

	i = 0;
	while (i < philo->global->n_o_p)
	{
		if (pthread_create(&philo[i].thread, NULL, \
		philo_actions, (void *)&philo[i]) != 0)
			return (0);
		i += 2;
	}
	my_usleep (10);
	i = 1;
	while (i < philo->global->n_o_p)
	{
		if (pthread_create(&philo[i].thread, NULL, \
		philo_actions, (void *)&philo[i]) != 0)
			return (0);
		i += 2;
	}
	pthread_create(&monitory, NULL, check_threads, (void *)philo);
	pthread_detach(monitory);
	return (1);
}

int	start_philosophie(t_per *philo, t_phi *p)
{
	if (!init_philos(philo))
	{
		free_resources (philo, p);
		return (0);
	}
	return (1);
}

t_per	*init_philo_data(t_phi *p)
{
	t_per	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_per) * p->n_o_p);
	if (!philo)
		return (0);
	while (i < p->n_o_p)
	{
		philo[i].id = i + 1;
		philo[i].eat_c = 0;
		philo[i].global = p;
		philo[i].t_t_d = p->t_t_d;
		philo[i].run_time = p->run_time;
		philo[i].last_time_eat = p->run_time;
		i++;
	}
	return (philo);
}

int	ft_philo(t_phi *p)
{
	t_per	*philo;
	int		i;

	i = -1;
	philo = init_philo_data(p);
	if (!philo)
		return (0);
	if (!init_mutexes(p, philo))
		return (0);
	if (pthread_mutex_init(&p->global_m, NULL) == 0)
		p->mtx_sta = 1;
	if (!start_philosophie(philo, p))
		return (0);
	while (++i < p->n_o_p)
		pthread_join(philo[i].thread, NULL);
	free_resources(philo, p);
	return (1);
}
