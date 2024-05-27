/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:30:15 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/07 16:46:29 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	check_the_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] && ft_strchr("-+", str[i]))
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_exit(char **args)
{
	if (args[1] && args[2])
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return (1);
	}
	if (check_the_number(args[1]))
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd("numeric argument required\n", 2);
		exit(255);
	}
	if (args[1])
		exit(ft_atoi(args[1]));
	exit(0);
	return (0);
}
