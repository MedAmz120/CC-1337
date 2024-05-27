/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:30:23 by moamzil           #+#    #+#             */
/*   Updated: 2022/10/30 16:19:52 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	hex_nbr_len(unsigned int num)
{
	int		i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(unsigned	int nb, char *base)
{
	if (nb < 0)
		nb *= nb;
	if (nb < 16)
		ft_putchar(base[nb]);
	else if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, base);
		ft_putnbr_base(nb % 16, base);
	}
	else
		ft_putchar(nb + 48);
}

int	hex_function(unsigned	int n, char *base)
{
	int	len;

	ft_putnbr_base(n, base);
	len = hex_nbr_len(n);
	return (len);
}
