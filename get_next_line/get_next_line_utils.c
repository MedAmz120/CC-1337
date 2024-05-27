/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:20:01 by moamzil           #+#    #+#             */
/*   Updated: 2022/11/29 14:59:10 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = -1;
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	while (++i < size)
		((char *)ptr)[i] = 0;
	return (ptr);
}

char	*ft_strjoin(char *buff, char *safe)
{
	int		i;
	int		j;
	char	*nsafe;

	i = 0;
	j = 0;
	if (!safe)
		safe = ft_calloc(1, 1);
	nsafe = ft_calloc(1, (ft_strlen(safe, 1) + ft_strlen(buff, 1) + 1));
	while (safe[i] != '\0')
	{
		nsafe[i] = safe[j];
		j++;
		i++;
	}
	j = 0;
	while (buff[j] != '\0')
	{
		nsafe[i] = buff[j];
		j++;
		i++;
	}
	free(safe);
	return (nsafe);
}

char	*ft_substr(char *safe)
{
	int		i;
	char	*line;
	int		len_to_nw;

	i = 0;
	len_to_nw = ft_strlen_v2(safe);
	line = ft_calloc(1, len_to_nw + 1);
	while (i < len_to_nw)
	{
		line[i] = safe[i];
		i++;
	}
	return (line);
}

size_t	ft_strlen_v2(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

size_t	ft_strlen(char *buff, int option)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!buff)
		buff = ft_calloc(1, 1);
	if (!option)
	{
		if (ft_strchr(buff, '\n'))
		{
			while (buff[i] && buff[i] != '\n')
				i++;
			i++;
		}
		while (buff[i++] != '\0')
			len++;
		return (len + 1);
	}
	else
		while (buff[i] != '\0')
			i++;
	return (i);
}
