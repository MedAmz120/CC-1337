/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:29:34 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/10 05:39:00 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_spaces(char *str, t_swp *s)
{
	int		i;
	size_t	space;

	i = -1;
	space = 0;
	while (str[++i])
	{
		if (str[i] == ' ')
			space++;
		else
			break ;
	}
	if (space == ft_strlen(str) || (ft_strlen(str) == 0))
		quit_program (s, 404);
}

void	triple_to_double(char ***tmp, t_swp *s)
{
	int		i;
	size_t	tab_len;

	i = -1;
	s->x = 1;
	s->y = 1;
	tab_len = t_len(tmp) + 2;
	s->avg = (char **)malloc(sizeof(char *) * tab_len);
	if (!s->avg)
		quit_program (s, 0);
	s->avg[0] = NULL;
	while (tmp[++i])
	{
		s->x = 1;
		while (tmp[i][s->x])
		{
			s->avg[s->y] = ft_strdup(tmp[i][s->x]);
			s->y++;
			s->x++;
		}
	}
	s->avg[s->y] = NULL;
	s->acs = tab_len - 2;
}
