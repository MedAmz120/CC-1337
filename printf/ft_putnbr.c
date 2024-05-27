/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:54:12 by moamzil           #+#    #+#             */
/*   Updated: 2022/10/29 23:26:16 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	nbr_len(int n)
{
	int		i;
	long	num;

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

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}

int	main_function(int n)
{
	int	len;

	ft_putnbr(n);
	len = nbr_len(n);
	return (len);
}
