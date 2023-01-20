/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:52:56 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/19 00:42:02 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*reader(int fd, char *str)
{
	char	*buffer;
	int		len;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	len = 1;
	while (!(ft_strchr(str, '\n')) && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == 0)
			break ;
		if (len == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[len] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*res;

	str = reader(fd, str);
	if (!str)
		return (NULL);
	res = get_ligne(str);
	str = get_extra(str);
	return (res);
}

void	freeall(t_vars *vars)
{
	free(vars->map);
}

int	check_path_e(char **map, int j, int i)
{
	if (map[j][i] == 'E')
	{
		if (map[j + 1][i] == 'P')
		{
			return (1);
		}
		if (map[j -1][i] == 'P')
		{
			return (1);
		}
		if (map[j][i +1] == 'P')
		{
			return (1);
		}
		if (map[j][i -1] == 'P')
		{
			return (1);
		}
	}
	return (0);
}
