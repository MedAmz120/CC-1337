/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 00:48:09 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/10 06:43:41 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	t_len(char ***tmp)
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
