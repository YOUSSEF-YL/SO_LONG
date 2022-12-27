/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:26:41 by ybachar           #+#    #+#             */
/*   Updated: 2022/12/27 15:22:33 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "so_long.h"

t_intvars  get_plyer_pos (char ** map)
{
    t_intvars var;
    var.i= 0;
	var.j = 0;
	while(map[var.j])
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


int	key_hook(char ** map ,int keycode)
{
    t_intvars intvar;
    t_vars	vars;

    intvar = get_plyer_pos (map);
    if ((keycode == 126 || keycode == 13) && map[intvar.j+1][intvar.i] != 'E' && map[intvar.j+1][intvar.i] != '1') //up
    {
       map[intvar.j-1][intvar.i] =  map[intvar.j][intvar.i];
       mlx_clear_window(vars.mlx,vars.win);
    }
    if ((keycode == 124 || keycode == 2)  && map[intvar.j][intvar.i+1] != 'E' && map[intvar.j][intvar.i+1] != '1') //r
    {   
        map[intvar.j][intvar.i+1] = map[intvar.j][intvar.i];
        mlx_clear_window(vars.mlx,vars.win);
    }
    if ((keycode == 125 || keycode == 1) && map[intvar.j+1][intvar.i] != 'E' && map[intvar.j+1][intvar.i] != '1') //d
    {
        map[intvar.j-1][intvar.i] = map[intvar.j][intvar.i];
        mlx_clear_window(vars.mlx,vars.win);
    }
    if ((keycode == 123 || keycode == 0) && map[intvar.j][intvar.i- 1] != 'E' && map[intvar.j][intvar.i -1] != '1') //l
    {
        map[intvar.j][intvar.i -1] = map[intvar.j][intvar.i];
        mlx_clear_window(vars.mlx,vars.win);
    }
    return (1);
}