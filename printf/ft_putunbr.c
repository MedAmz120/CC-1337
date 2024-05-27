/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:13:54 by moamzil           #+#    #+#             */
/*   Updated: 2022/10/29 23:31:41 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	unbr_len(unsigned int n)
{
	int				i;
	unsigned long	num;

	i = 0;
	num = n;
	if (n == 0)
		return (1);
	if (num < 0)
	{
		i++;
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	ft_putunbr(unsigned int n)
{
	unsigned long	num;

	num = n;
	if (num < 0)
	{
		num++;
	}
	if (num > 9)
	{
		ft_putunbr(num / 10);
		ft_putunbr(num % 10);
	}
	else
		ft_putchar(num + 48);
}

int	putunbr_main_function(unsigned int n)
{
	int	len;

	ft_putunbr(n);
	len = unbr_len(n);
	return (len);
}
