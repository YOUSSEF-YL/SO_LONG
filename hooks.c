/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:26:41 by ybachar           #+#    #+#             */
/*   Updated: 2022/12/26 22:39:42 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include "so_long.h"

t_intvars  get_ppos (char ** map)
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
		var.j++;
	}

     
    return (var);
}


int	key_hook(char ** map ,int keycode)
{
    struct vars var;
    
    var.i= 0;
	var.j = 0;
	while(map[var.j])
	{
		var.i = 0;
		while (map[var.j][var.i])
		{
			if (map[var.j][var.i] == 'p')
               break;
			var.i++;
		}
		var.j++;
	}
	
    t_vars	vars;
    
    // if (keycode == 126 || keycode == 13 && map[var.j+1][var.i] != 'E' && map[var.j+1][var.i] != '1') //up
    // {
    //    map[var.j-1][var.i] =  map[var.j][var.i];
    //    mlx_clear_window(vars.mlx,vars.win);
    // }
    // if (keycode == 124 || keycode == 2  && map[var.j][var.i+1] != 'E' && map[var.j][var.i+1] != '1') //r
    // {   
    //     map[var.j][var.i+1] = map[var.j][var.i];
    //     mlx_clear_window(vars.mlx,vars.win);
    // }
    // if (keycode == 125 || keycode == 1 && map[var.j+1][var.i] != 'E' && map[var.j+1][var.i] != '1') //d
    // {
    //     map[var.j-1][var.i] = map[var.j][var.i];
    //     mlx_clear_window(vars.mlx,vars.win);
    // }
    // if (keycode == 123 || keycode == 0 && map[var.j][var.i- 1] != 'E' && map[var.j][var.i -1] != '1') //l
    // {
    //     map[var.j][var.i -1] = map[var.j][var.i];
    //     mlx_clear_window(vars.mlx,vars.win);
    // }
    

   
    
    return (1);
}