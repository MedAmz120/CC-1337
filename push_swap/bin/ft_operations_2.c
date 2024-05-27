/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:38:43 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/06 18:50:45 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_swp *s, int msg)
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
	s->sta[s->acs - 1] = tmp;
	if (msg == 1)
		ft_printf("ra\n");
}

void	ft_rb(t_swp *s, int msg)
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
	s->stb[s->acs - 1] = tmp;
	if (msg == 1)
		ft_printf("rb\n");
}

void	ft_rr(t_swp *s)
{
	ft_ra(s, 0);
	ft_rb(s, 0);
	ft_printf("rr\n");
}

void	ft_rra(t_swp *s, int msg)
{
	int	i;
	int	j;
	int	c;
	int	tmp;

	j = 0;
	c = 0;
	i = s->acs - 1;
	tmp = s->sta[i];
	while (c < s->a_cnt - 1)
	{
		s->sta[i] = s->sta[(i - 1 + s->acs) % s->acs];
		i = (i - 1 + s->acs) % s->acs;
		c++;
	}
	s->sta[s->a_pos] = tmp;
	if (msg == 1)
		ft_printf("rra\n");
}

void	ft_rrb(t_swp *s, int msg)
{
	int	i;
	int	pos;
	int	hold;
	int	*temp;

	i = 0;
	hold = s->stb[s->acs - 1];
	pos = s->b_pos;
	temp = (int *)malloc(sizeof(int) * (s->b_cnt - 1));
	if (!temp)
		quit_program (s, 0);
	while (i < s->b_cnt - 1)
		temp[i++] = s->stb[pos++];
	s->stb[s->b_pos] = hold;
	i = 0;
	pos = 1;
	while (i < s->b_cnt - 1)
		s->stb[s->b_pos + (pos++)] = temp[i++];
	free(temp);
	if (msg == 1)
		ft_printf("rrb\n");
}
