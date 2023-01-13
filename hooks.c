/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:26:41 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/13 19:02:01 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_intvars	get_plyer_pos(char **map)
{
	t_intvars	var;

	var.i = 0;
	var.j = 0;
	while (map[var.j])
	{
		var.i = 0;
		while (map[var.j][var.i])
		{
			if (map[var.j][var.i] == 'P')
				break ;
			var.i++;
		}
		if (map[var.j][var.i] == 'P')
			break ;
		var.j++;
	}
	return (var);
}

int	get_c(char **map)
{
	t_intvars	intvar;

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

void	move_to(t_vars *vars, int j, int i, t_intvars intvar)
{
	int			w;
	static int	cc;
	void		*bg;
	void		*p;

	if (get_c(vars->map) == 0)
	{
		if (vars->map[j][i] == 'E')
		{
			vars->map[j][i] = vars->map[intvar.j][intvar.i];
			ft_printf("%s : %d\n", "movse", ++cc);
			ft_exit(vars);
		}
	}
	if (vars->map[j][i] != 'E')
	{
		vars->map[j][i] = vars->map[intvar.j][intvar.i];
		vars->map[intvar.j][intvar.i] = '0';
		bg = mlx_xpm_file_to_image(vars->mlx, "assets/green60.xpm", &w, &w);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, bg,
			intvar.i * 60, intvar.j * 60);
		p = mlx_xpm_file_to_image(vars->mlx, "assets/player.xpm", &w, &w);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, p, i * 60, j * 60);
		ft_printf("%s : %d\n", "moves ", ++cc);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	t_intvars	intvar;

	intvar = get_plyer_pos(vars->map);
	if ((keycode == 126 || keycode == 13) && vars->map
		[intvar.j - 1][intvar.i] != '1')
		move_to(vars, intvar.j - 1, intvar.i, intvar);
	else if ((keycode == 123 || keycode == 0) && vars->map
		[intvar.j][intvar.i - 1] != '1')
		move_to(vars, intvar.j, intvar.i - 1, intvar);
	else if ((keycode == 125 || keycode == 1) && vars->map
		[intvar.j + 1][intvar.i] != '1')
		move_to(vars, intvar.j + 1, intvar.i, intvar);
	else if ((keycode == 124 || keycode == 2) && vars->map
		[intvar.j][intvar.i + 1] != '1')
		move_to(vars, intvar.j, intvar.i + 1, intvar);
	else if (keycode == 53)
		ft_exit(vars);
	return (0);
}

int	check_map_compos(char **map)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] && map[j][i] != '1' && map[j][i] != 'E' && map[j][i]
				!= 'P' && map[j][i] != 'C' && map[j][i]
					!= '0' && map[j][i] != '\n')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
