/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:12:56 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/08 22:32:16 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_apply(char *str, t_bns *s)
{
	if (ft_strcmp(str, "sa\n"))
		ft_sa(s);
	else if (ft_strcmp(str, "sb\n"))
		ft_sb(s);
	else if (ft_strcmp(str, "ss\n"))
		ft_ss(s);
	else if (ft_strcmp(str, "pa\n"))
		ft_pa(s);
	else if (ft_strcmp(str, "pb\n"))
		ft_pb(s);
	else if (ft_strcmp(str, "ra\n"))
		ft_ra(s);
	else if (ft_strcmp(str, "rb\n"))
		ft_rb(s);
	else if (ft_strcmp(str, "rr\n"))
		ft_rr(s);
	else if (ft_strcmp(str, "rra\n"))
		ft_rra(s);
	else if (ft_strcmp(str, "rrb\n"))
		ft_rrb(s);
	else if (ft_strcmp(str, "rrr\n"))
		ft_rrr(s);
	else
		return (0);
	return (1);
}

void	ft_apply_instructions(t_bns *s)
{
	char	*line;
	size_t	bytes;

	s->a_cnt = s->arg_c;
	s->a_pos = 0;
	s->b_cnt = 0;
	s->b_pos = s->arg_c;
	s->stb = (int *)malloc(sizeof(int) * s->arg_c);
	if (!s->stb)
		quit_program_bns (s, 0);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!ft_apply(line, s))
		{
			free(line); 
			quit_program_bns (s, 404);
		}
		free(line);
	}
}
