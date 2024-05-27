/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:25:41 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/10 07:57:28 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_duplicate(t_swp *s)
{
	int	i;
	int	y;

	i = 0;
	while (i < s->acs)
	{
		y = i + 1;
		if (s->sta[i] > 2147483647)
			return (0);
		while (y < s->acs)
		{
			if (s->sta[y] == s->sta[i])
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	ch_mp(char	*str)
{
	int	i;
	int	mine;
	int	plus;

	i = 0;
	plus = 0;
	mine = 0;
	while ((str[i] == '-' || str[i] == '+')
		|| (str[i] == '\t' || str[i] == ' '))
	{
		if (str[i] == '-')
			mine++;
		else if (str[i] == '+')
			plus++;
		i++;
	}
	if ((mine > 1 || plus > 1))
		return (0);
	if (mine >= 1 && plus >= 1)
		return (0);
	if (mine == ft_strlen(str) || plus == ft_strlen(str))
		return (0);
	return (1);
}

int	che_rg(char *str)
{
	int	i;

	i = 0;
	if ((*str) == '+' || (*str) == '-')
		str++;
	while ((*str) == '0')
		str++;
	if (*str == '\0')
		return (1);
	return (!(ft_strlen(str) > 11));
}

int	check_chars(char	*str)
{
	int	i;

	i = 0;
	if (!(ch_mp(str)))
		return (0);
	if (!(che_rg(str)))
		return (0);
	while ((str[i] == '-' || str[i] == '+')
		|| (str[i] == '\t' || str[i] == ' '))
		++i;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	if (str[0] == '-' && str[1] == '\0')
		return (0);
	return (1);
}

int	arg_check(char **av, int ac, t_swp *s)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	s->sta = (int *)malloc(sizeof(int) * (ac - 1));
	if (!s->sta)
		exit (1);
	while (av[++y])
		if ((!(check_chars(av[y]))))
			return (0);
	y = -1;
	while (i < ac)
	{
		s->temp = push_swap_atoi(av[i++]);
		if (s->temp >= -2147483648 && s->temp <= 2147483647)
			s->sta[++y] = s->temp;
		else
			return (0);
	}
	if (!(check_duplicate(s)))
		return (0);
	return (1);
}
