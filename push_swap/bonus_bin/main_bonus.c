/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:12:33 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/10 07:32:10 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_bns	swp;

	swp.sta = NULL;
	swp.stb = NULL;
	swp.avg_b = NULL;
	if (ac > 1)
	{
		check_double_quo_bns(av, &swp, &ac);
		ac = swp.arg_c + 1;
		if (arg_check_bns(swp.avg_b, ac, &swp))
		{
			if (check_sorted_bns(&swp))
				quit_program_bns (&swp, 1);
			else
			{
				ft_apply_instructions(&swp);
				check_sorted_fnl(&swp);
			}
		}
		quit_program_bns (&swp, 0);
	}
	return (0);
}
