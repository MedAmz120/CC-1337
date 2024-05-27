/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:03:57 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/04 16:26:01 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_clean_spaces(t_tools *t)
{
	char	*tmp;

	tmp = ft_strtrim(t->rline, " ");
	free(t->rline);
	t->rline = tmp;
}

int	find_close_quotes(char *line, int pos, int *d_s, int c)
{
	int	j;

	j = pos + 1;
	*d_s += 1;
	while (line[j] && line[j] != c)
		j++;
	if (line[j] == c)
		*d_s += 1;
	return (j - pos);
}

int	count_double_quotes(char *line)
{
	int	i;
	int	d;
	int	s;

	i = 0;
	d = 0;
	s = 0;
	while (line[i])
	{
		if (line[i] == DOUBLE_Q)
			i += find_close_quotes(line, i, &d, DOUBLE_Q);
		if (line[i] == SINGLE_Q)
			i += find_close_quotes(line, i, &d, SINGLE_Q); 
		i++;
	}
	if ((d > 0 && d % 2 != 0) || (s > 0 && s % 2 != 0))
		return (0);
	return (1);
}

void	find_env_path(t_tools *t)
{
	int		i;
	char	*tmp;

	i = 0;
	while (t->envp[i])
	{
		if (!ft_strncmp(t->envp[i], "PATH=", 5))
		{
			tmp = ft_substr (t->envp[i], 5, ft_strlen(t->envp[i]));
			if (!tmp)
				quit_program (t, EXIT_FAILURE);
			t->paths = ft_split(tmp, ':');
			free (tmp);
		}
		i++;
	}
}

void	find_pwd(t_tools *t)
{
	int		i;
	char	*tmp;
	char	*tmp_2;

	i = 0;
	while (t->envp[i])
	{
		if (!ft_strncmp(t->envp[i], "PWD=", 4))
		{
			tmp = ft_substr(t->envp[i], 4, ft_strlen(t->envp[i]) - 4);
			if (!tmp)
				quit_program (t, EXIT_FAILURE);
			t->pwd = tmp;
		}
		if (!ft_strncmp(t->envp[i], "OLDPWD=", 7))
		{
			tmp_2 = ft_substr(t->envp[i], 7, ft_strlen(t->envp[i]) - 7);
			if (!tmp_2)
				quit_program(t, EXIT_FAILURE);
			t->old_pwd = tmp_2;
		}
		i++;
	}
}
