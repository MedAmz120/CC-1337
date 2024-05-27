/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:06:24 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/07 15:49:23 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	env(t_env *env_list)
{
	t_env	*temp;

	temp = env_list;
	while (temp)
	{
		if (temp && temp->value != NULL)
			printf("%s=%s\n", temp->key, temp->value);
		temp = temp->next;
	}
}
