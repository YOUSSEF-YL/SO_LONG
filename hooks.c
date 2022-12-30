/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:26:41 by ybachar           #+#    #+#             */
/*   Updated: 2022/12/30 17:33:51 by ybachar          ###   ########.fr       */
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
   t_vars	var;

	 intvar = get_plyer_pos (vars->map);
	 
    if ((keycode == 126 || keycode == 13) ) //up
    {
		//&& vars->map[intvar.j+1][intvar.i] != 'E' && vars->map[intvar.j+1][intvar.i] != '1'
		printf("hiho");
       vars->map[intvar.j-1][intvar.i] =  vars->map[intvar.j][intvar.i];
	   vars->map[intvar.j][intvar.i] = '0';
	   //draw_to_win(var,vars->map);
		printmap(vars->map);
      // mlx_clear_window(vars->mlx,vars->win);
    }
    if ((keycode == 124 || keycode == 2)  && vars->map[intvar.j][intvar.i+1] != 'E' && vars->map[intvar.j][intvar.i+1] != '1') //r
    {   
        vars->map[intvar.j][intvar.i+1] = vars->map[intvar.j][intvar.i];
		vars->map[intvar.j][intvar.i] = '0';
        mlx_clear_window(vars->mlx,vars->win);
    }
    if ((keycode == 125 || keycode == 1) && vars->map[intvar.j+1][intvar.i] != 'E' && vars->map[intvar.j+1][intvar.i] != '1') //d
    {
        vars->map[intvar.j-1][intvar.i] = vars->map[intvar.j][intvar.i];
		vars->map[intvar.j][intvar.i] = '0';
        mlx_clear_window(vars->mlx,vars->win);
    }
    if ((keycode == 123 || keycode == 0) && vars->map[intvar.j][intvar.i- 1] != 'E' && vars->map[intvar.j][intvar.i -1] != '1') //l
    {
        vars->map[intvar.j][intvar.i -1] = vars->map[intvar.j][intvar.i];
		vars->map[intvar.j][intvar.i] = '0';
        mlx_clear_window(vars->mlx,vars->win);
    }
	// printf("%d",intvar.i);
	// printf("+++++++++++++\n");
	// printf("%d",intvar.j);
 	// printf("+++++++++++++\n");
	// printf("%d\n",keycode);
    return (0);
}