/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:00:58 by moamzil           #+#    #+#             */
/*   Updated: 2023/10/05 19:58:06 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_for_nme(t_per *philo)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (1)
	{
		if (philo[i].global->n_m_e != -1)
		{
			if (philo[i].eat_c >= philo[i].global->n_m_e)
				nb++;
			if (nb == philo[i].global->n_o_p)
			{
				philo[i].global->should_break = -1;
				return (1);
			}
			if (i == philo[i].global->n_o_p - 1)
				break ;
			if (++i == philo->global->n_o_p)
				i = 0;
		}
		else
			break ;
	}
	return (0);
}

int	check_nme(t_per *philo)
{
	pthread_mutex_lock(&philo->global->global_m);
	if (philo->global->n_m_e != -1)
	{
		if (check_for_nme(philo))
		{
			philo->global->should_break = -1;
			pthread_mutex_unlock(&philo->global->global_m);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->global->global_m);
	return (0);
}

void	free_resources(t_per *philo, t_phi *p)
{
	int	i;

	i = 0;
	if (p->mtx_sta)
		pthread_mutex_destroy(&p->global_m);
	if (p->forks_sta)
	{
		while (i < p->n_o_f)
		{
			pthread_mutex_destroy(&p->mutex[i]);
			i++;
		}
	}
	free(philo);
}

int	check_str(char *str)
{
	int	i;

	i = -1;
	if (str[i + 1] == '-' || str[i + 1] == '+')
		i++;
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	nbr;
	int	i;

	i = 0;
	neg = 1;
	nbr = 0;
	while (str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f'
		|| str[i] == ' ' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (str[i] - '0') + (nbr * 10);
		i++;
	}
	return (nbr * neg);
}
