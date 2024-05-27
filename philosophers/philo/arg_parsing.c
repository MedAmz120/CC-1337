/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:03:49 by moamzil           #+#    #+#             */
/*   Updated: 2023/10/04 18:31:22 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_parsing(t_phi *p, char **av)
{
	if (!(ft_nopf(p, av[1])) || !(ft_ttd(p, av[2]))
		|| !(ft_tte(p, av[3])) || !(ft_tts(p, av[4])))
	{
		printf("Error\n: Invalid arguments :\n");
		return (0);
	}
	if (p->acs == 6)
	{
		if (!(ft_nme(p, av[5])))
		{
			printf("Error\n: Invalid arguments :\n");
			return (0);
		}
	}
	else
		p->n_m_e = -1;
	return (1);
}
