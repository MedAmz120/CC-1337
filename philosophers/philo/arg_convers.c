/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_convers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:12:32 by moamzil           #+#    #+#             */
/*   Updated: 2023/10/04 18:31:19 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_nopf(t_phi *p, char *str)
{
	if (!(check_str(str)))
		return (0);
	p->n_o_p = ft_atoi(str);
	if (p->n_o_p < 1)
		return (0);
	p->n_o_f = p->n_o_p;
	return (1);
}

int	ft_ttd(t_phi *p, char *str)
{
	if (!(check_str(str)))
		return (0);
	p->t_t_d = ft_atoi(str);
	if (p->t_t_d <= 0)
		return (0);
	return (1);
}

int	ft_tte(t_phi *p, char *str)
{
	if (!(check_str(str)))
		return (0);
	p->t_t_e = ft_atoi(str);
	if (p->t_t_e <= 0)
		return (0);
	return (1);
}

int	ft_tts(t_phi *p, char *str)
{
	if (!(check_str(str)))
		return (0);
	p->t_t_s = ft_atoi(str);
	if (p->t_t_s <= 0)
		return (0);
	return (1);
}

int	ft_nme(t_phi *p, char *str)
{
	if (!(check_str(str)))
		return (0);
	p->n_m_e = ft_atoi(str);
	if (p->n_m_e < 1)
		return (0);
	return (1);
}
