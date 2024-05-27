/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:02:36 by moamzil           #+#    #+#             */
/*   Updated: 2022/11/30 12:46:56 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>

int		ft_strchr(char *s, int c);
char	*keep_aftr_nw(char *safe);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *buff, char *safe);
char	*ft_substr(char *safe);
size_t	ft_strlen_v2(char *buff);
size_t	ft_strlen(char *buff, int option);
char	*get_next_line(int fd);

#endif
