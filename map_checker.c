/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:29:16 by yiachar           #+#    #+#             */
/*   Updated: 2023/01/17 21:16:01 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_path_valid(char **map)
{
	t_intvars	var;

	var.i = 0;
	var.j = 0 ;
	while (map[var.j])
	{
		var.i = 0;
		while (map[var.j][var.i])
		{
			if (map[var.j][var.i] == 'C' )
			{
				return (0);
			}
			var.i++;
		}
		var.j++;
	}
	return (1);
}

int	check_liens_l(char **map, char *map_path)
{
	t_intvars	intvar;

	intvar.i = 0;
	intvar.j = map_lines(map_path) - 1;
	while (intvar.i < intvar.j)
	{
		if (ft_strlen(map[0]) - 1 != ft_strlen(map[intvar.i]) - 1)
			return (0);
		if (ft_strlen(map[0]) - 1 != ft_strlen(map[intvar.j]))
			return (0);
		intvar.i++;
	}
	return (1);
}

int	check_walls(char **map, char *map_path)
{
	t_intvars	intvar;

	intvar.j = 0;
	intvar.i = 0;
	while (intvar.i < ft_strlen(map[intvar.j]) - 1)
	{
		if (map[0][intvar.i] != '1')
			return (0);
		if (map[map_lines(map_path) - 1][intvar.i] != '1')
			return (0);
		intvar.i++;
	}
	intvar.e = ft_strlen(map[intvar.j]) - 2;
	while (map[intvar.j])
	{
		if (map[intvar.j][intvar.e] != '1')
			return (0);
		if (map[intvar.j][0] != '1')
			return (0);
		intvar.j++;
	}
	return (1);
}

char	**check_path(char **map, int j, int i)
{
	if (map[j][i] == 'P')
	{
		if (map[j + 1][i] == '0' || map[j + 1][i] == 'C' )
		{
			map[j + 1][i] = 'P';
			check_path(map, j + 1, i);
		}
		if (map[j - 1][i] == '0' || map[j - 1][i] == 'C' )
		{
			map[j - 1][i] = 'P';
			check_path(map, j - 1, i);
		}
		if (map[j][i + 1] == '0' || map[j][i + 1] == 'C' )
		{
			map[j][i + 1] = 'P';
			check_path(map, j, i + 1);
		}
		if (map[j][i - 1] == '0' || map[j][i -1] == 'C' )
		{
			map[j][i - 1] = 'P';
			check_path(map, j, i - 1);
		}
	}
	j++;
	return (map);
}

int	map_req(char **map)
{
	t_intvars	var;

	var.p = 0;
	var.e = 0;
	var.c = 0;
	var.j = 0;
	while (map[var.j])
	{
		var.i = 0;
		while (map[var.j][var.i])
		{
			if (map[var.j][var.i] == 'P')
				var.p = var.p + 1;
			if (map[var.j][var.i] == 'E')
				var.e = var.e + 1;
			if (map[var.j][var.i] == 'C')
				var.c = var.c + 1;
			var.i++;
		}
		var.j++;
	}
	if (var.p < 1 || var.c < 1 || var.e < 1 || var.p > 1 || var.e > 1)
		return (0);
	return (1);
}
