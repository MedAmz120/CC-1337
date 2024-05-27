/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:04:01 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/07 19:04:14 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	get_env_pos(char *str, t_tools *t)
{
	int		i;
	char	*tmp;

	i = 0;
	while (t->envp[i])
	{
		tmp = ft_substr(t->envp[i], 0, ft_strllen(t->envp[i], 0, '='));
		if (!ft_strncmp(str, tmp, ft_strlen(t->envp[i])))
		{
			free(tmp);
			return (i);
		}
		free(tmp);
		tmp = NULL;
		i++;
	}
	return (-1);
}

char	*get_env_value(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	i++;
	res = ft_substr(str, i, ft_strllen(str, i, 0));
	return (res);
}

char	*ft_envcpy(char *str, int i, t_tools *t)
{
	int		len;
	int		env_pos;
	char	*res;

	len = i + 1;
	if (str[i] == '$')
	{
		while (!is_whitespace(str[len]) && str[len] != 34 && str[len]
			&& str[len] != '$' && str[len] != '=' && str[len] != '/'
			&& str[len] != '\\' && str[len] != SINGLE_Q)
			len++;
		len--;
	}
	if (t->env_name)
		free(t->env_name);
	t->env_name = ft_substr(str, i + 1, len - i);
	env_pos = get_env_pos(t->env_name, t);
	if (env_pos == -1)
		return (0);
	res = get_env_value(t->envp[env_pos]);
	return (res);
}

size_t	ft_strlen_skip(char *str, char c)
{
	size_t	len;
	size_t	c_count;

	len = 0;
	c_count = 0;
	while (str[len])
	{
		if (str[len] == c)
			c_count++;
		len++;
	}
	return (len - c_count);
}

char	*remove_double_quotes(char *str, t_tools *t)
{
	int		i;
	int		j;
	char	*res;

	i = -1;
	j = -1;
	t->in_double_quotes = 0;
	res = malloc(sizeof(char) * (ft_strlen_skip(str, '\\') - 1));
	if (!res)
		quit_program(t, EXIT_FAILURE);
	if (str[++i] == DOUBLE_Q)
		t->in_double_quotes = 1;
	while (str[++i])
	{
		if (assign_single(str, i, t))
			res[++j] = str[i];
		else if (assign_double(str, i))
			res[++j] = str[i];
		else if (assign_random(str, i))
			res[++j] = str[i];
	}
	res[++j] = 0;
	return (res);
}
