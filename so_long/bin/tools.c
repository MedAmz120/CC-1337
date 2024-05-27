/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:55:13 by moamzil           #+#    #+#             */
/*   Updated: 2023/08/11 19:55:20 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_long_join(char *dest, char *src, char c, int pos)
{
	int	i;

	i = 0;
	while (src[pos] && src[pos] != c)
	{
		dest[i] = src[pos];
		pos++;
		i++;
	}
	dest[i] = 0;
}

int	so_long_split_2(char **res, char *str, char c)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			res[x] = (char *)malloc(sizeof(char) * (word_len(str, c) + 1));
			if (!res[x])
				return (0);
			so_long_join(res[x], str, c, i);
			while (str[i] && str[i] != c)
				i++;
			x++;
		}
		else
			i++;
	}
	res[x] = 0;
	return (1);
}

char	**so_long_split(char *str, char c)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * (ft_word_cnt(str, c) + 1));
	if (!res)
		return (0);
	if (!so_long_split_2(res, str, c))
		return (0);
	return (res);
}

char	*put_all_in_one(char **lines, t_map *p)
{
	char	*one_line;
	int		i;
	int		j;
	int		x;

	i = -1;
	x = 0;
	one_line = malloc(sizeof(char) * (table_size_counter(p)
				* ft_strlen(lines[0]) + 1));
	if (!one_line)
		return (0);
	while (lines[++i])
	{
		j = -1;
		while (lines[i][++j])
			one_line[x++] = lines[i][j];
	}
	one_line[x] = 0;
	i = -1;
	while (one_line[++i])
		if (one_line[i] == 'C')
			p->score += 10;
	return (one_line);
}
