/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:29:16 by yiachar           #+#    #+#             */
/*   Updated: 2023/01/01 12:45:50 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"


// int c_cherch(char *str ,char c)
// {
// 	int i ;
	
// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i]== c)
// 			return (1);
// 		i++;
// 	}
// 	return(0);
// }

// int get_c_i(char* line,int c)
// {
// 	int  i;
// 	i = 0;
// 	while (line[i] != '\0')
// 	{
// 		if (line[i] ==  c)
// 		{
// 			return (i);
// 		}
// 		i++;
// 	}
// 	return (0);
// }



int check_liens_l(char **map)
{
	t_intvars intvar;

    int i;
	intvar.i = 1;
	intvar.j = map_lines("map.ber")-1;
	
    while (intvar.i < intvar.j)
	{
		if (ft_strlen(map[0])-1 != ft_strlen(map[intvar.i])-1)
			return (0);	
		intvar.i++;
	}
 	return(1);
}

int check_walls(char **map)
{
	t_intvars intvar;
	
    intvar.j = 0;
	intvar.i = 0;
	
	// while (j <= map_lines("map.ber")-1)
	// {
		while (intvar.i < ft_strlen(map[intvar.j])-1) //-1
		{
			if (map[0][intvar.i] != '1') //top_l
				return (1);
			if (map[map_lines("map.ber")-1][intvar.i] != '1') // last_l
				return (1);
			 intvar.i++;
		}
	//}
	intvar.e = ft_strlen(map[intvar.j])-2;
	while (map[intvar.j])
	{
			if (map[intvar.j][intvar.e] != '1') //R_l
				return (1);	
			if (map[intvar.j][0] != '1') //l_l
				return (1);
		intvar.j++;
	}
	
 return(0);
}


void check_pathe(char ** map ,int j , int i)
{
			if (map[j][i] == 'p')
			{
				if (map[j+1][i] == '0' || map[j+1][i] == 'c' || map[j+1][i] == 'e')//up
					{
						map[j+1][i] = 'p';
						check_pathe(map,j+1,i );
					}
				if (map[j-1][i] == '0' || map[j-1][i] == 'c' || map[j-1][i] == 'e')//down
					{
						map[j-1][i] = 'p';
						check_pathe(map,j-1 , i);
					}
				if (map[j][i+1] == '0' || map[j][i+1] == 'c' || map[j][i+1] == 'e')//r
					{
						map[j][i+1] = 'p';
						check_pathe(map,j , i+1);
					}
				if (map[j][i-1] == '0' || map[j][i-1] == 'c' || map[j][i-1] == 'e')//l
					{
						map[j][i-1] = 'p';
						check_pathe(map, j, i-1);
					}
			}
		j++;
}

int map_req(char ** map)

{
	struct vars var;

	var.p = 0;
	var.e = 0;
	var.c = 0;
	var.j = 0;
	while(map[var.j])
	{
		var.i = 0;
		while (map[var.j][var.i])
		{
			if(map[var.j][var.i] == 'p')
				var.p = var.p +1;
			if(map[var.j][var.i] == 'e')
				var.e = var.e +1;
			if(map[var.j][var.i] == 'c')
				var.c = var.c +1;
		 var.i++;
		}
		var.j++;
	}
	if(var.p < 1 || var.c < 1 || var.e < 1 || var.p > 1 || var.e > 1)
		return (0);
	return(1);
}
