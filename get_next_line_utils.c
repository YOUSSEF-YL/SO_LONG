/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:53:37 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/16 12:54:47 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s2 && !s1)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*get_ligne(char *str)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * i + 2);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_extra(char *str)
{
	int		k;
	char	*extra;
	int		j;

	k = 0;
	while (str[k] && str[k] != '\n')
		k++;
	if (str[k] == '\0' || (str[k] == '\n' && str[k + 1] == '\0'))
	{
		free(str);
		return (NULL);
	}
	extra = malloc(sizeof(char) * (ft_strlen(str) - k + 1));
	j = 0;
	k = k + 1;
	while (str[k] != '\0')
	{
		extra[j] = str[k];
		j++;
		k++;
	}
	extra[j] = '\0';
	free(str);
	return (extra);
}
