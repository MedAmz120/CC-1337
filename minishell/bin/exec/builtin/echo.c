/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:19:50 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/07 15:48:36 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_size(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	is_n(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' && s[i + 1] == 'n')
		i++;
	else
		return (0);
	while (s[i])
	{
		if (s[i] == 'n')
			i++;
		else
			return (0);
	}
	return (1);
}

void	write_newline(int new_line)
{
	if (new_line == 0)
		write(1, "\n", 1);
}

void	echo(char **args)
{
	int	i;
	int	j;
	int	new_line;

	if (!args[1])
	{
		write(1, "\n", 1);
		return ;
	}
	i = ft_size(args);
	j = 1;
	new_line = 0;
	while (args[j][0] != 0 && is_n(args[j]))
	{
		j++;
		new_line = 1;
	}
	while (j < i)
	{
		ft_putstr_fd(args[j], 1);
		if (args[j + 1])
			write(1, " ", 1);
		j++;
	}
	write_newline(new_line);
}
