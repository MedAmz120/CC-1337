/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:29:10 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/06 18:57:19 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_small_number_pb(int *tab, t_swp *s)
{
	int	i;
	int	j;

	i = s->a_pos;
	s->s_num = tab[i];
	while (i < s->acs)
	{
		j = s->a_pos;
		while (j < s->acs)
		{
			if (tab[i] > tab[j] && tab[j] < s->s_num)
				s->s_num = tab[j];
			j++;
		}
		i++;
	}
}

long	ft_get_position(t_swp *s)
{
	int		j;
	long	i;

	j = 0;
	i = s->a_pos;
	while (j < s->a_cnt)
	{
		if (s->sta[i] == s->s_num)
			return (i);
		i++;
		j++;
	}
	return (0);
}

void	ft_small_out(t_swp *s)
{
	s->temp = ft_get_position(s);
	if (s->temp == s->a_pos + 1)
	{
		ft_sa(s, 1);
		s->temp = ft_get_position(s);
	}
	if (s->temp == s->a_pos)
	{
		ft_pb(s);
		return ;
	}
	if (s->temp != s->a_pos && s->temp != s->a_pos + 1)
	{
		ft_rra(s, 1);
		ft_small_out(s);
	}
}

void	ft_sort_5(t_swp *s)
{
	int	i;

	i = s->a_pos;
	ft_small_number_pb(s->sta, s);
	ft_small_out(s);
	ft_small_number_pb(s->sta, s);
	ft_small_out(s);
	if (!check_part_sorted(s))
		ft_sort_3(s);
	if (s->stb[s->b_pos] < s->stb[s->b_pos + 1])
		ft_sb(s, 1);
	ft_pa(s);
	ft_pa(s);
}
