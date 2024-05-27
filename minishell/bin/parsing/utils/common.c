/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:01:31 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/08 02:39:22 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	check_empty_cmd(t_tools *t)
{
	ft_clean_spaces(t);
	if (t->rline[0] == '\0')
		return (0);
	return (1);
}

char	**realloc_2d(char **tab, char *str, t_tools *t)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (ft_2dlen(tab) + 2));
	if (!ret)
		quit_program (t, EXIT_FAILURE);
	while (tab && tab[i] != NULL)
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	ret[i] = ft_substr(str, 0, ft_strlen(str));
	ret[i + 1] = NULL;
	if (str)
		free (str);
	if (tab)
		free_2darr(tab, t);
	return (ret);
}

size_t	ft_2dlen(char **tab)
{
	size_t	len;

	len = 0;
	while (tab && tab[len] != NULL)
		len++;
	return (len);
}

size_t	ft_strllen(char *str, int start, char end)
{
	size_t	i;

	i = 0;
	while (str[start] != end && str[start])
	{
		start++;
		i++;
	}
	return (i);
}

char	**ft_2dup(char **tab)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * (ft_2dlen(tab) + 1));
	if (!res)
		exit (0);
	while (tab[i])
	{
		res[j] = ft_strdup (tab[i]);
		i++;
		j++;
	}
	res[j] = 0;
	return (res);
}
