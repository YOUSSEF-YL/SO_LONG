/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:04:43 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/11 18:41:02 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_lines(char	*map)
{
	char	*str;
	int		fd;
	int		i;

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

char	**get_map(int lines, char *map_path)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	map = (char **)malloc(map_lines(map_path) * sizeof(char *));
	fd = open(map_path, O_RDONLY);
	while (i <= lines - 1)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	map[map_lines(map_path)] = 0;
	return (map);
}

int	ft_exit(void)
{
	exit(0);
}

// void	put_bg(t_vars var)
// {
// 	void	*xpm;
// 	char	*bg;

// 	bg = "assets/bg.xpm";
// 	xpm = mlx_xpm_file_to_image(var.mlx, bg, &var.img_width, &var.img_height);
// 	mlx_put_image_to_window(var.mlx, var.mlx_win, xpm, 0, 0);
// }

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

int	is_map_valid(char **map, char *map_path)
{
	t_intvars	intvar ;

	intvar = get_plyer_pos(map);
	if (check_walls(map, map_path) == 0)
		ft_printf("Error:\n The map must be surrounded by walls \n");
	if (map_req(map) == 0)
		ft_printf("Error:\n The map has to be"
			"constructed with required components\n");
	if (check_liens_l(map, map_path) == 0)
		ft_printf("Error:\n The map must be rectangular \n");
	if (check_map_compos(map) == 0)
		ft_printf("Error:\nThe map has to be constructed"
			"with required components only \n");
	if ((map_req(map) == 1) && (check_liens_l(map, map_path) == 1)
		&& (check_walls(map, map_path) == 1) && (check_map_compos(map) == 1))
	{
		if (is_path_valid(check_path(map, intvar.j, intvar.i)) == 0)
			printf("Error:\n There is no valid path in the map.\n");
		else
			return (1);
	}
	return (0);
}
