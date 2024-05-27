/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:26:04 by moamzil           #+#    #+#             */
/*   Updated: 2022/10/30 17:26:46 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	printf_sep(const char *s, va_list args, size_t i)
{
	int	cr;

	cr = 0;
	if (s[i] == '%')
	{
		i++;
		if (s[i] == '%')
			cr += ft_putchar('%');
		if (s[i] == 'c')
			cr += ft_putchar(va_arg(args, int));
		if (s[i] == 's')
			cr += ft_putstr(va_arg(args, char *));
		if (s[i] == 'p')
			cr += ft_adress(va_arg(args, unsigned long), "0123456789abcdef");
		if (s[i] == 'd' || s[i] == 'i')
			cr += main_function(va_arg(args, int));
		if (s[i] == 'u')
			cr += putunbr_main_function(va_arg(args, unsigned int));
		if (s[i] == 'x')
			cr += hex_function(va_arg(args, unsigned int), "0123456789abcdef");
		if (s[i] == 'X')
			cr += hex_function(va_arg(args, unsigned int), "0123456789ABCDEF");
	}
	return (cr);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			cr;
	int			count;
	size_t		i;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			write (1, &str[i], 1);
			count++;
		}
		else
		{
			cr = printf_sep(str, args, i);
			count = cr + count;
			i++;
		}
		i++;
	}
	return (count);
}
