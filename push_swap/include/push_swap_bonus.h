/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:44:07 by moamzil           #+#    #+#             */
/*   Updated: 2023/09/10 06:46:54 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# define INT_MIN 2147483647

# include <stdlib.h>
# include "../src/ft_printf/ft_printf.h"
# include "../src/libft/libft.h"
# include "../src/get_next_line/get_next_line.h"

typedef struct push_bonus
{
	int		*sta;
	int		*stb;
	char	**avg_b;
	int		a_pos;
	int		b_pos;
	int		arg_c;
	long	temp;
	int		b_cnt;
	int		a_cnt;
	int		ca_se;
	int		x;
	int		y;
}	t_bns;

/* Program Function */

int		arg_check_bns(char **av, int ac, t_bns *s);
void	free_triple_bns(t_bns *s, char ***tmp);
size_t	t_len_bns(char ***tmp);
void	triple_to_double_bns(char ***tmp, t_bns *s);
int		ch_mp_bns(char	*str);
void	check_double_quo_bns(char **str, t_bns *s, int *ac);
int		ft_word_cswp_bns(char const *s, char c);
void	check_spaces_bns(char *str, t_bns *s);
int		check_chars_bns(char *str);
int		check_duplicate_bns(t_bns *s);
long	push_swap_atoi_bns(char *str);
void	check_sorted_fnl(t_bns *s);
int		check_sorted_bns(t_bns *s);
void	ft_apply_instructions(t_bns *s);
int		ft_apply(char *str, t_bns *s);
void	quit_program_bns(t_bns *s, int pte);

/* Operations Functions */

void	ft_sa(t_bns *s);
void	ft_sb(t_bns *s);
void	ft_ss(t_bns *s);
void	ft_pa(t_bns *s);
void	ft_pb(t_bns *s);
void	ft_ra(t_bns *s);
void	ft_rb(t_bns *s);
void	ft_rr(t_bns *s);
void	ft_rra(t_bns *s);
void	ft_rrb(t_bns *s);
void	ft_rrr(t_bns *s);

#endif