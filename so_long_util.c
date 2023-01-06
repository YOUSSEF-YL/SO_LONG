/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:04:43 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/06 16:46:05 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_lines(char *map)
{
	char *str;
	int fd;
	int i;

	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		i++;
		str = get_next_line(fd);
	}
	close(fd);
	free(str);
	return (i);
}

char **get_map(int lines)
{
	char **map;
	int i;
	int fd;

	i = 0;
	map = (char **)malloc(map_lines("map.ber") * sizeof(char *));
	fd = open("map.ber", O_RDONLY);
	while (i <= lines - 1)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	map[map_lines("map.ber")] = 0;
	return (map);
}

int ft_exit(void)
{
	exit(0);
}

void put_bg(t_vars var)
{
	void *xpm;
	char *bg;

	bg = "assets/bg.xpm";
	xpm = mlx_xpm_file_to_image(var.mlx, bg, &var.img_width, &var.img_height);
	mlx_put_image_to_window(var.mlx, var.mlx_win, xpm, 0, 0);
}

int is_map_valid(char **map)
{
	if ((map_req(map) == 1) && (check_liens_l(map) == 1) && (check_walls(map) == 1)  && (check_map_compos(map) == 1))
		return (1);
	return (0);
}
