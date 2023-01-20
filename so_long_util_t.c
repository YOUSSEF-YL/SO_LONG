/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:04:43 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/20 17:12:44 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_intvars	get_e_pos(char **map)
{
	t_intvars	var;

	var.i = 0;
	var.j = 0;
	while (map[var.j])
	{
		var.i = 0;
		while (map[var.j][var.i])
		{
			if (map[var.j][var.i] == 'E')
				break ;
			var.i++;
		}
		if (map[var.j][var.i] == 'E')
			break ;
		var.j++;
	}
	return (var);
}

void	map_errors(char **map, char *map_path)
{
	if (check_walls(map, map_path) == 0)
		ft_printf("Error:\n The map must be surrounded by walls \n");
	if (map_req(map) == 0)
		ft_printf("Error:\n The map has to be"
			" constructed with required components\n");
	if (check_liens_l(map, map_path) == 0)
		ft_printf("Error:\n The map must be rectangular \n");
	if (check_map_compos(map) == 0)
		ft_printf("Error:\nThe map has to be constructed"
			" with required components only \n");
}

int	is_map_valid(char **map, char *map_path)
{
	t_intvars	intvar ;
	t_intvars	intvar_e ;

	intvar = get_plyer_pos(map);
	intvar_e = get_e_pos(map);
	map_errors(map, map_path);
	if ((map_req(map) == 1) && (check_liens_l(map, map_path) == 1)
		&& (check_walls(map, map_path) == 1) && (check_map_compos(map) == 1))
	{
		if (is_path_valid(check_path(map, intvar.j, intvar.i)) == 0)
			ft_printf("Error:\n There is no valid path in the map.\n");
		else
		{
			if (check_path_e(check_path(map, intvar.j, intvar.i)
					, intvar_e.j, intvar_e.i) == 0)
			{
				ft_printf("Error:\n There is no valid path in the map.\n");
			}
			else
				return (1);
		}
	}
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
}

void	start(char **map)
{
	free_map(map);
	free(map);
}
