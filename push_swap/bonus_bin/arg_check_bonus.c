/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:12:45 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/10 07:58:17 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	check_duplicate_bns(t_bns *s)
{
	int	i;
	int	y;

	i = 0;
	while (i < s->arg_c)
	{
		y = i + 1;
		if (s->sta[i] > 2147483647)
			return (0);
		while (y < s->arg_c)
		{
			if (s->sta[y] == s->sta[i])
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	ch_mp_bns(char	*str)
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
	if (mine > 1 || plus > 1)
		return (0);
	if (mine >= 1 && plus >= 1)
		return (0);
	if (mine == ft_strlen(str) || plus == ft_strlen(str))
		return (0);
	return (1);
}

int	che_rg_bns(char *str)
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

int	check_chars_bns(char	*str)
{
	int	i;

	i = 0;
	if (!(ch_mp_bns(str)))
		return (0);
	if (!(che_rg_bns(str)))
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

int	arg_check_bns(char **av, int ac, t_bns *s)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	s->sta = (int *)malloc(sizeof(int) * (ac - 1));
	if (!s->sta)
		exit (1);
	while (av[++y])
		if (!(check_chars_bns(av[y])))
			quit_program_bns (s, 404);
	y = -1;
	while (i < ac)
	{
		s->temp = push_swap_atoi_bns(av[i++]);
		if (s->temp >= -2147483648 && s->temp <= 2147483647)
			s->sta[++y] = s->temp;
		else
			quit_program_bns (s, 404);
	}
	if (!(check_duplicate_bns(s)))
		quit_program_bns (s, 404);
	return (1);
}
