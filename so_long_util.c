/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:04:43 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/17 22:13:20 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_lines(char	*map)
{
	char	*str;
	int		fd;
	int		i;

	fd = open(map, O_RDONLY);
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == '\0')
			break ;
		i++;
		free(str);
	}
	close(fd);
	return (i);
}

char	**get_map(char *map_path)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	map = (char **)malloc((map_lines(map_path)+1) * sizeof(char *));
	fd = open(map_path, O_RDONLY);
	while (1)
	{
		map[i] = get_next_line(fd);
		if (map[i] == '\0')
			break ;
		i++;
	}
	if (!map)
		exit(0);
	close (fd);
	return (map);
}

int	ft_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	free_map(vars->map);
	free(vars->map);
	exit(0);
}

int	map_name(char *name )
{
	int	i;

	i = ft_strlen(name) - 1;
	if (name[i] != 'r' || name[i -1] != 'e' )
		return (0);
	if (name[i -2] != 'b' || name[i - 3] != '.' )
		return (0);
	return (1);
}
