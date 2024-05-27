/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:53:22 by moamzil           #+#    #+#             */
/*   Updated: 2022/10/30 16:17:59 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	adress_len(unsigned long n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_put_adress(unsigned long nbr, char *base)
{
	if (nbr < 16)
		ft_putchar(base[nbr]);
	else if (nbr >= 16)
	{
		ft_put_adress(nbr / 16, base);
		ft_put_adress(nbr % 16, base);
	}
}

int	ft_adress(unsigned long n, char *base)
{
	int	len;

	ft_putstr("0x");
	ft_put_adress(n, base);
	len = adress_len(n);
	return (len + 2);
}
