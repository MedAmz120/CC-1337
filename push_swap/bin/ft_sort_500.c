/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:29:25 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/06 18:58:31 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_500(t_swp *s)
{
	ft_create_chunk(s);
	ft_duplicate_stack(s->sta, s->chnk, s->acs);
	ft_sort_chunk(s);
	ft_pushto_stb(s);
	ft_pushto_sta(s);
}
