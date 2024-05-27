/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:41:45 by rrakman           #+#    #+#             */
/*   Updated: 2023/12/07 15:15:43 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	update_myenv(char *key, char *value, t_tools *t)
{
	t_env	*temp;

	temp = t->env_list;
	while (temp)
	{
		if (ft_strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = ft_strdup(value);
			break ;
		}
		temp = temp->next;
	}
}

void	changedir(char *path, t_tools *t)
{
	char	*oldpwd;
	char	*pwd;

	if (path == NULL)
		printf("cd: %s not set", path);
	oldpwd = getcwd(NULL, 0);
	if (chdir(path) != 0)
		printf("cd: %s: No such file or directory\n", path);
	else
	{
		pwd = getcwd(NULL, 0);
		add_oldpwd_tomyenv("OLDPWD", oldpwd, t);
		update_myenv("PWD", pwd, t);
	}
}

void	ft_cd(char *path, t_tools *t)
{
	if (path == NULL || (ft_strcmp(path, "~") == 0))
		changedir(getenv("HOME"), t);
	else
		changedir(path, t);
}
