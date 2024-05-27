/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:21:03 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/17 13:52:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

size_t	ft_strlen_no_newlines(const char *s1)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s1[i] && s1[i] == ' ')
		i++;
	while (s1[i])
	{
		if (s1[i] == '\n')
			break ;
		len++;
		i++;
	}
	return (len);
}

char	*ft_strdup_no_newlines(char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc((ft_strlen_no_newlines(s1) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[i] == ' ' && s1[i])
		i++;
	while (s1[i] && s1[i] != '\n')
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free (s1);
	s1 = NULL;
	return (str);
}

size_t	ft_2dlen(char **tab)
{
	size_t	len;

	len = 0;
	while (tab && tab[len] != NULL)
		len++;
	return (len);
}

char	**realloc_2d(char **tab, char *str)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (ft_2dlen(tab) + 2));
	if (!ret)
		exit (0);
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
		free_2darr(tab);
	return (ret);
}
