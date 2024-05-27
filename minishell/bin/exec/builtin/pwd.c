/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:42:33 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/07 15:50:47 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	pwd(void)
{
	char	*buff;

	buff = NULL;
	buff = getcwd(NULL, 0);
	ft_putstr_fd(buff, 1);
	write(1, "\n", 1);
	free(buff);
}
