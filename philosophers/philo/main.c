/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:22:46 by moamzil           #+#    #+#             */
/*   Updated: 2023/10/05 13:19:36 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_phi	p;

	if (ac == 5 || ac == 6)
	{
		p.acs = ac;
		if (!arg_parsing(&p, av))
			return (1);
		p.run_time = get_timestamp_ms();
		if (!ft_philo(&p))
			return (1);
	}
	else
		printf("Error\n: Too few arguments :\n");
	return (0);
}
