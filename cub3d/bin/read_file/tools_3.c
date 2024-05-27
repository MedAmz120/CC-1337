/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:59:22 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_ranges(char *str)
{
	char	*tmp;
	int		start;
	int		num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 3)
	{
		start = i;
		while (str[i] != ',' && str[i])
			i++;
		tmp = ft_substr(str, start, i - start);
		num = ft_atoi(tmp);
		if (num > 255 || num < 0)
		{
			free (tmp);
			return (-1);
		}
		free (tmp);
		i++;
		j++;
	}
	return (1);
}

int	count_commas(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (-1);
	return (0);
}
