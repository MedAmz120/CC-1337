/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:04:39 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/07 19:03:29 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	copy_env(char *res, char *str, char *env, t_tools *t)
{
	while (env[t->j])
	{
		res[t->x] = env[t->j];
		t->x++;
		t->j++;
	}
	t->i++;
	while (str[t->i] != ' ' && str[t->i] != '$' && str[t->i] && str[t->i] != '/'
		&& str[t->i] != '=' && str[t->i] != '\\' && str[t->i] != SINGLE_Q)
		t->i++;
	t->i -= 1;
	t->x -= 1;
	t->flag = 1;
}

void	ft_expand_in(char *str, char *res, char *env, t_tools *t)
{
	if (!ft_strncmp(&str[t->i + 1], t->env_name, ft_strlen(t->env_name))
		&& t->flag != 1)
		copy_env(res, str, env, t);
	else
	{
		res[t->x] = '$';
		if (str[t->i] == '$')
			t->i++;
		t->x++;
		while (str[t->i] != ' ' && str[t->i] != '$' && str[t->i])
		{
			res[t->x] = str[t->i];
			t->i++;
			t->x++;
		}
	}
}

char	*ft_append_env(char *str, char *env, int env_len, t_tools *t)
{
	char	*res;

	t->i = 0;
	t->x = 0;
	t->j = 0;
	t->flag = 0;
	res = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(env))
				- (env_len)));
	if (!res)
		return (0);
	while (str[t->i])
	{
		if (str[t->i] == '$' && t->flag != 1 && (t->i == 0 || str[t->i \
				- 1] != '\\'))
			ft_expand_in(str, res, env, t);
		else
			res[t->x] = str[t->i];
		t->x++;
		t->i++;
	}
	res[t->x] = '\0';
	return (res);
}

char	*init_append(char *str, char *res, size_t len, t_tools *t)
{
	char	*tmp;

	if (!res)
		res = ft_strdup("");
	tmp = NULL;
	tmp = ft_append_env(str, res, len, t);
	if (str)
		free(str);
	str = ft_strdup(tmp);
	if (tmp)
		free(tmp);
	return (str);
}

char	*ft_expandit(char *str, t_tools *t)
{
	int		i;
	char	*res;

	i = -1;
	res = NULL;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == '$' && (i == 0 || str[i - 1] != '\\')
			&& str[0] != SINGLE_Q)
		{
			if (str[i + 1] == '?' && str[i + 1])
			{
				t->env_name = ft_strdup("?");
				res = ft_itoa(t->exit_status);
			}
			else
				res = ft_envcpy(str, i, t);
			str = init_append(str, res, ft_strlen(t->env_name), t);
			i = -1;
		}
	}
	quotes_backslash(str, t, res);
	return (str);
}
