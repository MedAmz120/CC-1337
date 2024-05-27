/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:54:36 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/06 18:55:21 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_range(t_swp *s)
{
	if (s->sta[s->a_pos] >= s->chnk[s->start]
		&& s->sta[s->a_pos] <= s->chnk[s->stop])
	{
		ft_pb(s);
		if (s->stop < s->acs - 1)
		{
			s->start++;
			s->stop++;
		}
	}
	else if (s->sta[s->a_pos] < s->chnk[s->start])
	{
		ft_pb(s);
		ft_rb(s, 1);
		if (s->stop < s->acs - 1)
		{
			s->start++;
			s->stop++;
		}
	}
	else
		ft_ra(s, 1);
}

void	ft_pushto_stb(t_swp *s)
{
	int	i;

	i = 0;
	s->start = 0;
	s->stop = RANGE_SIZE_100;
	if (s->a_cnt < 15)
		s->stop = 5;
	if (s->acs > 100)
		s->stop = RANGE_SIZE_500;
	while (s->a_cnt >= 0)
	{
		if (s->a_cnt == 0)
			break ;
		ft_range(s);
	}
	while (i < s->acs)
	{
		s->sta[i] = 9999;
		i++;
	}
}

void	ft_sort_chunk(t_swp *s)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < s->acs)
	{
		if (s->chnk[i] > s->chnk[i + 1])
		{
			tmp = s->chnk[i];
			s->chnk[i] = s->chnk[i + 1];
			s->chnk[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
		if (i + 1 == s->acs)
			break ;
	}
}

void	ft_sort_100(t_swp *s)
{
	ft_create_chunk(s);
	ft_duplicate_stack(s->sta, s->chnk, s->acs);
	ft_sort_chunk(s);
	ft_pushto_stb(s);
	ft_pushto_sta(s);
}
