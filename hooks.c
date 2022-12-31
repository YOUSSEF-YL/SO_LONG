/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:26:41 by ybachar           #+#    #+#             */
/*   Updated: 2022/12/31 18:19:01 by ybachar          ###   ########.fr       */
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

int move_to(t_vars *vars, int j,int i,t_intvars intvar,int c)
{
	 vars->map[j][i] = vars->map[intvar.j][intvar.i];
		vars->map[intvar.j][intvar.i] = '0';
		put_bg(*vars);
	    draw_to_win(*vars,vars->map);
		c += 1;
	return(c);
}

int	key_hook(int keycode,t_vars *vars)
{
   t_intvars intvar;
	 intvar = get_plyer_pos (vars->map);
	 static int c = 0;

    if ((keycode == 126 || keycode == 13) && vars->map[intvar.j-1][intvar.i] != 'E' && vars->map[intvar.j-1][intvar.i] != '1') //up
		c = move_to(vars,intvar.j-1,intvar.i,intvar,c);
    if ((keycode == 123 || keycode == 0)  && vars->map[intvar.j][intvar.i-1] != 'E' && vars->map[intvar.j][intvar.i-1] != '1') //L
		c = move_to(vars,intvar.j,intvar.i-1,intvar,c);
    if ((keycode == 125 || keycode == 1) && vars->map[intvar.j+1][intvar.i] != 'E' && vars->map[intvar.j+1][intvar.i] != '1') //d
		c = move_to(vars,intvar.j+1,intvar.i,intvar,c);
    if ((keycode == 124 || keycode == 2) && vars->map[intvar.j][intvar.i+ 1] != 'E' && vars->map[intvar.j][intvar.i +1] != '1') //R
		c = move_to(vars,intvar.j,intvar.i+1,intvar,c);
	if (keycode == 53)
		exit(0);
	ft_printf("%s : %d\n","movse",c);
    return (0);
}