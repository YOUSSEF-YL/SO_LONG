/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:26:41 by ybachar           #+#    #+#             */
/*   Updated: 2022/12/31 15:32:30 by ybachar          ###   ########.fr       */
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

void printmap(char ** map)
{
	int j;
	int i;
	i =0;
	j =0;
	while(map[j])
	{
		i = 0;
		while (map[j][i])
		{
			printf("%c",map[j][i]);
			i++;
		}
		j++;
	}
}

int	key_hook(int keycode,t_vars *vars)
{
   t_intvars intvar;
	 intvar = get_plyer_pos (vars->map);
	 static int c = 0;
	 
	 printf("%s = %d\n","movse",c);
	 
    if ((keycode == 126 || keycode == 13) && vars->map[intvar.j-1][intvar.i] != 'E' && vars->map[intvar.j-1][intvar.i] != '1') //up
    {
	
       vars->map[intvar.j-1][intvar.i] =  vars->map[intvar.j][intvar.i];
	   vars->map[intvar.j][intvar.i] = '0';
	    put_bg(*vars);
	    draw_to_win(*vars,vars->map);
		c += 1;
     //  mlx_clear_window(vars->mlx,vars->win);
    }
    if ((keycode == 123 || keycode == 0)  && vars->map[intvar.j][intvar.i-1] != 'E' && vars->map[intvar.j][intvar.i-1] != '1') //L
    {   
        vars->map[intvar.j][intvar.i-1] = vars->map[intvar.j][intvar.i];
		vars->map[intvar.j][intvar.i] = '0';
		put_bg(*vars);
	    draw_to_win(*vars,vars->map);
		c += 1;
        //mlx_clear_window(vars->mlx,vars->win);
    }
    if ((keycode == 125 || keycode == 1) && vars->map[intvar.j+1][intvar.i] != 'E' && vars->map[intvar.j+1][intvar.i] != '1') //d
    {
        vars->map[intvar.j+1][intvar.i] = vars->map[intvar.j][intvar.i];
		vars->map[intvar.j][intvar.i] = '0';
        put_bg(*vars);
	    draw_to_win(*vars,vars->map);
		c += 1;
    }
    if ((keycode == 124 || keycode == 2) && vars->map[intvar.j][intvar.i+ 1] != 'E' && vars->map[intvar.j][intvar.i +1] != '1') //R
    {
        vars->map[intvar.j][intvar.i +1] = vars->map[intvar.j][intvar.i];
		vars->map[intvar.j][intvar.i] = '0';
		put_bg(*vars);
	    draw_to_win(*vars,vars->map);
		c += 1;
        //mlx_clear_window(vars->mlx,vars->win);
    }
	if (keycode == 53)
	{
		//mlx_destroy_window(vars->mlx, vars->win);
			exit(0);
	}
	
	printf("%d",keycode);
	printf("%s = %d\n","movse",c);
    return (0);
}