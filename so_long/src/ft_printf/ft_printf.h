/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:06:18 by moamzil           #+#    #+#             */
/*   Updated: 2022/10/30 16:19:34 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	main_function(int n);
int	putunbr_main_function(unsigned int n);
int	hex_function(unsigned int n, char *base);
int	ft_adress(unsigned long n, char *base);
int	ft_putstr(char	*str);

#endif
