/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_Bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:33:53 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/07 13:51:28 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_intvars get_en_pos(char **map)
{
    t_intvars var;

    var.i = 0;
    var.j = 0;
    while (map[var.j])
    {
        var.i = 0;
        while (map[var.j][var.i])
        {
            if (map[var.j][var.i] == 'E')
                // break ;
                animation();
            var.i++;
        }
        // if (map[var.j][var.i] == 'E')
        // 	break ;
        var.j++;
    }
    return (var);
}

void animation(t_vars *vars, t_intvars intvar)
{
    int j;
    int i;
    j = rand();
    i = rand();
        if (vars->map[j][i] == 'E')
    {
        if (get_c(vars->map) == 0)
        {
            vars->map[j][i] = vars->map[intvar.j][intvar.i];
            exit(0);
        }
    }
    if (vars->map[j][i] != 'E')
    {
        vars->map[j][i] = vars->map[intvar.j][intvar.i];
        vars->map[intvar.j][intvar.i] = '0';
        mlx_clear_window(vars->mlx, vars->mlx_win);
    }
    draw_to_win(*vars, vars->map);
}