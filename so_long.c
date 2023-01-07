/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:59:44 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/07 21:20:38 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void apptowindow(void *mlx, void *mlx_win, int img_width, int img_height, char *img_path, int x, int y)
{
	char *path;
	void *xpm;

	path = "assets/green60.xpm";
	if (path != img_path)
	{
		xpm = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
		mlx_put_image_to_window(mlx, mlx_win, xpm, x, y);
	}
	xpm = mlx_xpm_file_to_image(mlx, img_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, xpm, x, y);
	mlx_destroy_image(mlx, xpm);
}

void put_imag_to_w(char **map, t_intvars intvar, t_vars var, t_map map_util)
{
	map_util.collectible = "assets/collectiblee.xpm";
	map_util.player = "assets/player.xpm";
	map_util.exit = "assets/door.xpm";
	map_util.wall = "";
	map_util.empty = "assets/green60.xpm";
	if (map[intvar.j][intvar.i] == '1')
		apptowindow(var.mlx, var.mlx_win, var.img_width, var.img_height,
					"assets/d.xpm", map_util.x, map_util.y);
	else if (map[intvar.j][intvar.i] == '0')
		apptowindow(var.mlx, var.mlx_win, var.img_width,
					var.img_height, map_util.empty,
					map_util.x, map_util.y);
	else if (map[intvar.j][intvar.i] == 'C')
		apptowindow(var.mlx, var.mlx_win, var.img_width, var.img_height,
					map_util.collectible, map_util.x, map_util.y);
	else if (map[intvar.j][intvar.i] == 'E')
		apptowindow(var.mlx, var.mlx_win, var.img_width, var.img_height,
					map_util.exit, map_util.x, map_util.y);
	else if (map[intvar.j][intvar.i] == 'P')
		apptowindow(var.mlx, var.mlx_win, var.img_width, var.img_height,
					map_util.player, map_util.x, map_util.y);
}

void draw_to_win(t_vars var, char **map)
{
	t_intvars intvar;
	t_map map_util;

	map_util.y = 0;
	map_util.x = 0;
	intvar.j = 0;
	intvar.i = 0;
	while (map[intvar.j])
	{
		intvar.i = 0;
		while (map[intvar.j][intvar.i])
		{
			put_imag_to_w(map, intvar, var, map_util);
			intvar.i++;
			map_util.x = map_util.x + 60;
		}
		map_util.x = 0;
		map_util.y = map_util.y + 60;
		intvar.j++;
	}
}

int main(int ac, char **av)
{
	t_vars var;
	t_intvars intvar;
	int fd;
	// if (is_map_valid(var.map))
	// {
		
	// }
	// else	
	// 	ft_printf("invalid map");


	var.map = (char **)malloc(map_lines("map.ber") * sizeof(char *));
		var.map = get_map(map_lines("map.ber"));
		fd = open("map.ber", O_RDONLY);
		intvar.i = 60 * (ft_strlen(var.map[0]) - 1);
		intvar.j = 60 * map_lines("map.ber");
		var.mlx = mlx_init();
		var.mlx_win = mlx_new_window(var.mlx, intvar.i, intvar.j, "So_long");
		// put_bg(var);
		draw_to_win(var, var.map);
		mlx_key_hook(var.mlx_win, key_hook, &var);
		mlx_hook(var.mlx_win, 17, 0, ft_exit, &var);
		mlx_loop(var.mlx);
	// printf("%d",check_map_compos(var.map));
}

// gcc  -o mlx so_long.c  -lmlx -framework OpenGL -framework AppKit
// gcc so_long.c  -lmlx -framework OpenGL -framework AppKit
