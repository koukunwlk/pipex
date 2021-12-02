/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaro-d <mamaro-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:22:29 by mamaro-d          #+#    #+#             */
/*   Updated: 2021/12/02 19:37:05 by mamaro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

int	ft_strncmp(char *str1, char *str2, int n)
{
	while (--n > 0 && *str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str2 - *str1);
}

char	*path_join(char *path, char *cmd)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char) * (ft_strchr(path, 0) + \
								ft_strchr(cmd, 0) + 2));
	i = 0;
	j = 0;
	while (path[j])
		joined[i++] = path[j++];
	joined[i++] = '/';
	j = 0;
	while (cmd[j])
		joined[i++] = cmd[j++];
	joined[i] = 0;
	return (joined);
}

void free_args(char **ptr)
{
	int i;

	i = 0;
	while(ptr[i++])
		free((void *)ptr[i]);
	free(ptr);
}
