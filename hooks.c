/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:26:41 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/07 21:23:29 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_intvars get_plyer_pos(char **map)
{
	t_intvars var;

	var.i = 0;
	var.j = 0;
	while (map[var.j])
	{
		var.i = 0;
		while (map[var.j][var.i])
		{
			if (map[var.j][var.i] == 'P')
				break;
			var.i++;
		}
		if (map[var.j][var.i] == 'P')
			break;
		var.j++;
	}
	return (var);
}

// void printmap(char ** map)
// {
// 	int j;
// 	int i;
// 	i =0;
// 	j =0;
// 	while(map[j])
// 	{
// 		i = 0;
// 		while (map[j][i])
// 		{
// 			printf("%c",map[j][i]);
// 			i++;
// 		}
// 		j++;
// 	}
// }

int get_c(char **map)
{
	t_intvars intvar;

	intvar.i = 0;
	intvar.j = 0;
	intvar.c = 0;
	while (map[intvar.j])
	{
		intvar.i = 0;
		while (map[intvar.j][intvar.i])
		{
			if (map[intvar.j][intvar.i] == 'C')
				intvar.c++;
			intvar.i++;
		}
		intvar.j++;
	}
	return (intvar.c);
}

int move_to(t_vars *vars, int j, int i, t_intvars intvar, int c)
{
	int w;
	printf("%d\n", get_c(vars->map));
	if (get_c(vars->map) == 0)
	{
		if (vars->map[j][i] == 'E')
		{
			vars->map[j][i] = vars->map[intvar.j][intvar.i];
			// apptowindow();
			exit(0);
		}
	}
	if (vars->map[j][i] != 'E')
	{

		vars->map[j][i] = vars->map[intvar.j][intvar.i];
		vars->map[intvar.j][intvar.i] = '0';
		void *bg = mlx_xpm_file_to_image(vars->mlx, "assets/green60.xpm", &w, &w);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, bg, intvar.i * 60, intvar.j * 60);
		void *p = mlx_xpm_file_to_image(vars->mlx, "assets/player.xpm", &w, &w);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, p, i * 60, j * 60);
		c += 1;
		ft_printf("%s : %d\n", "movse", c);
		//  mlx_clear_window(vars->mlx, vars->mlx_win);
	}
	// draw_to_win(*vars, vars->map);

	return (c);
}

int key_hook(int keycode, t_vars *vars)
{
	t_intvars intvar;
	static int c = 0;

	intvar = get_plyer_pos(vars->map);
	if ((keycode == 126 || keycode == 13) && vars->map
													 [intvar.j - 1][intvar.i] != '1')
		c = move_to(vars, intvar.j - 1, intvar.i, intvar, c);
	else if ((keycode == 123 || keycode == 0) && vars->map
														 [intvar.j][intvar.i - 1] != '1')
		c = move_to(vars, intvar.j, intvar.i - 1, intvar, c);
	else if ((keycode == 125 || keycode == 1) && vars->map
														 [intvar.j + 1][intvar.i] != '1')
		c = move_to(vars, intvar.j + 1, intvar.i, intvar, c);
	else if ((keycode == 124 || keycode == 2) && vars->map
														 [intvar.j][intvar.i + 1] != '1')
		c = move_to(vars, intvar.j, intvar.i + 1, intvar, c);
	else if (keycode == 53)
		exit(0);
	return (0);
}
