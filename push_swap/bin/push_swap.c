/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:20:08 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/08 22:09:51 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_swap(t_swp *s)
{
	s->b_pos = s->acs;
	s->a_pos = 0;
	s->b_cnt = 0;
	s->a_cnt = s->acs;
	s->stb = (int *)malloc(sizeof(int) * s->acs);
	if (!s->stb)
		quit_program (s, 0);
	if (s->acs == 2)
		if (s->sta[0] > s->sta[1])
			ft_sa(s, 1);
	if (s->acs == 3)
		ft_sort_3(s);
	if (s->acs > 3 && s->acs <= 5)
		ft_sort_5(s);
	if (s->acs > 5 && s->acs <= 100)
		ft_sort_100(s);
	if (s->acs > 100)
		ft_sort_500(s);
}
