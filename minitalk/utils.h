/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:14:49 by moamzil           #+#    #+#             */
/*   Updated: 2023/01/09 19:03:40 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
