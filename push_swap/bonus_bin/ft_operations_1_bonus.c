/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:10:36 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/06 14:17:36 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	ft_sa(t_bns *s)
{
	int	tmp;

	if (s->a_cnt > 1)
	{
		tmp = s->sta[s->a_pos];
		s->sta[s->a_pos] = s->sta[s->a_pos + 1];
		s->sta[s->a_pos + 1] = tmp;
	}
}

void	ft_sb(t_bns *s)
{
	int	tmp;

	if (s->b_cnt > 1)
	{
		tmp = s->stb[s->b_pos];
		s->stb[s->b_pos] = s->stb[s->b_pos + 1];
		s->stb[s->b_pos + 1] = tmp;
	}
}

void	ft_ss(t_bns *s)
{
	ft_sa(s);
	ft_sb(s);
}

void	ft_pa(t_bns *s)
{
	if (s->b_cnt < 1)
		return ;
	s->sta[s->a_pos - 1] = s->stb[s->b_pos];
	s->stb[s->b_pos] = 9999;
	s->b_pos++;
	s->a_pos--;
	s->a_cnt++;
	s->b_cnt--;
}

void	ft_pb(t_bns *s)
{
	if (s->a_cnt < 1)
		return ;
	if (s->b_cnt != s->arg_c)
		s->b_pos--;
	s->stb[s->b_pos] = s->sta[s->a_pos];
	s->a_pos++;
	s->a_cnt--;
	s->b_cnt++;
}
