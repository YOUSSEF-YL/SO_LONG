/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:59:44 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/20 17:13:55 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	apptowindow(t_vars vars, char *img_path, int x, int y)
{
	char	*path;
	void	*xpm;

	path = "assets/green60.xpm";
	if (path != img_path)
	{
		xpm = mlx_xpm_file_to_image(vars.mlx, path,
				&vars.img_width, &vars.img_height);
		if (!xpm)
		{
			ft_printf("Error :\n mising assets");
			ft_exit(&vars);
		}
		mlx_put_image_to_window(vars.mlx, vars.mlx_win, xpm, x, y);
	}
	xpm = mlx_xpm_file_to_image(vars.mlx, img_path,
			&vars.img_width, &vars.img_height);
	if (!xpm)
	{
		ft_printf("Error :\n mising assets");
		ft_exit(&vars);
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, xpm, x, y);
	mlx_destroy_image(vars.mlx, xpm);
}

void	put_imag_to_w(char **map, t_intvars intvar, t_vars var, t_map map_util)
{
	map_util.collectible = "assets/collectiblee.xpm";
	map_util.player = "assets/player.xpm";
	map_util.exit = "assets/door.xpm";
	map_util.wall = "assets/d.xpm";
	map_util.empty = "assets/green60.xpm";
	if (map[intvar.j][intvar.i] == '1')
		apptowindow(var, map_util.wall, map_util.x, map_util.y);
	else if (map[intvar.j][intvar.i] == '0')
		apptowindow(var, map_util.empty, map_util.x, map_util.y);
	else if (map[intvar.j][intvar.i] == 'C')
		apptowindow(var, map_util.collectible, map_util.x, map_util.y);
	else if (map[intvar.j][intvar.i] == 'E')
		apptowindow(var, map_util.exit, map_util.x, map_util.y);
	else if (map[intvar.j][intvar.i] == 'P')
		apptowindow(var, map_util.player, map_util.x, map_util.y);
}

void	draw_to_win(t_vars var, char **map)
{
	t_intvars	intvar;
	t_map		map_util;

	map_util.y = 0;
	map_util.x = 0;
	intvar.j = 0;
	intvar.i = 0;
	while (var.map[intvar.j])
	{
		intvar.i = 0;
		while (var.map[intvar.j][intvar.i])
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

void	mlx_tools(t_vars var, t_intvars intvar)
{
	var.mlx = mlx_init();
				var.mlx_win = mlx_new_window(var.mlx,
			intvar.i, intvar.j, "So_long");
	draw_to_win(var, var.map);
	mlx_key_hook(var.mlx_win, key_hook, &var);
	mlx_hook(var.mlx_win, 17, 0, ft_exit, &var);
	mlx_loop(var.mlx);
}

int	main(int ac, char **av)
{
	t_vars		var;
	t_intvars	intvar;

	if (ac == 2)
	{
		var.map = get_map(av[1]);
		if (map_name(av[1]) == 0)
		{
			ft_printf("The map name is invalid  \n");
			start(var.map);
		}
		else
		{
			if (is_map_valid(var.map, av[1]))
			{
				start(var.map);
				var.map = get_map(av[1]);
				intvar.i = 60 * (ft_strlen(var.map[0]) - 1);
				intvar.j = 60 * map_lines(av[1]) - 1;
				mlx_tools(var, intvar);
			}
			else
				free_map(var.map);
		}
	}
}

// gcc  -o mlx so_long.c  -lmlx -framework OpenGL -framework AppKit
// gcc so_long.c  -lmlx -framework OpenGL -framework AppKit
