/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:10:42 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/08 22:52:51 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	ft_ra(t_bns *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s->sta[s->a_pos];
	while (i < s->a_cnt)
	{
		s->sta[s->a_pos + i] = s->sta[s->a_pos + i + 1];
		i++;
	}
	s->sta[s->arg_c - 1] = tmp;
}

void	ft_rb(t_bns *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s->stb[s->b_pos];
	while (i < s->b_cnt)
	{
		s->stb[s->b_pos + i] = s->stb[s->b_pos + i + 1];
		i++;
	}
	s->stb[s->arg_c - 1] = tmp;
}

void	ft_rr(t_bns *s)
{
	ft_ra(s);
	ft_rb(s);
}

void	ft_rra(t_bns *s)
{
	int	i;
	int	j;
	int	c;
	int	tmp;

	j = 0;
	c = 0;
	i = s->arg_c - 1;
	tmp = s->sta[i];
	while (c < s->a_cnt - 1)
	{
		s->sta[i] = s->sta[(i - 1 + s->arg_c) % s->arg_c];
		i = (i - 1 + s->arg_c) % s->arg_c;
		c++;
	}
	s->sta[s->a_pos] = tmp;
}

void	ft_rrb(t_bns *s)
{
	int	i;
	int	pos;
	int	hold;
	int	*temp;

	i = 0;
	hold = s->stb[s->arg_c - 1];
	pos = s->b_pos;
	temp = (int *)malloc(sizeof(int) * (s->b_cnt - 1));
	if (!temp)
		quit_program_bns (s, 0);
	while (i < s->b_cnt - 1)
		temp[i++] = s->stb[pos++];
	s->stb[s->b_pos] = hold;
	i = 0;
	pos = 1;
	while (i < s->b_cnt - 1)
	{
		s->stb[s->b_pos + pos] = temp[i];
		pos++;
		i++; 
	}
	free(temp);
}
