/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 05:50:32 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/10 06:51:29 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	free_triple_bns(t_bns *s, char ***tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp[i]) 
	{
		j = 1;
		while (tmp[i][j])
		{
			free(tmp[i][j]);
			j++;
		}
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

size_t	t_len_bns(char ***tmp)
{
	int		i;
	int		j;
	size_t	tab_len;

	i = 0;
	tab_len = 0;
	while (tmp[i])
	{
		j = 1;
		while (tmp[i][j])
		{
			tab_len++;
			j++;
		}
		i++;
	}
	return (tab_len);
}
