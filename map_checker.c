/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:29:16 by yiachar           #+#    #+#             */
/*   Updated: 2022/12/24 11:57:29 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"


int c_cherch(char *str ,char c)
{
	int i ;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i]== c)
			return (1);
		i++;
	}
	return(0);
}

int check_liens_l(char **map)
{
    int j;
    j = 1;
    while (j <= map_lines("map.txt")-1)
	{
		if (ft_strlen(map[0]) != ft_strlen(map[j]))
				return (1);
		j++;
	}
	
 return(0);
}

int check_walls(char **map)
{
    int j;
	int i;
	
    j = 0;
	i = 0;
	
	// while (j <= map_lines("map.txt")-1)
	// {
		while (i < ft_strlen(map[j])-1) //-1
		{
			if (map[0][i] != '1') //top_l
				return (1);
			if (map[map_lines("map.txt")-1][i] != '1') // last_l
				return (1);
			 i++;
		}
	//}
	int f = ft_strlen(map[j])-2;
	while (map[j])
	{
			if (map[j][f] != '1') //R_l
				return (1);	
			if (map[j][0] != '1') //l_l
				return (1);
		j++;
	}
	
 return(0);
}
int get_c_i(char* line,int c)
{
	int  i;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] ==  c)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

int check_pathe(char **map)
{
	int j;
	int i;
	j =0;
	while (map[j])
	{
		i = 0;
		int res;
		
		res = get_c_i(map[j],'p');
		while (map[j][i])
		{
			
			if (res > 0)
				return (res);
			i++;
		}
		j ++;
	}
	return(0);
}

void scratch(char ** map ,int j , int i)
{
			if (map[j][i] == 'p')
			{
				if (map[j+1][i] == '0' || map[j+1][i] == 'c' || map[j+1][i] == 'e')//up
					{
						map[j+1][i] = 'p';
						scratch(map,j+1,i );
					}
				if (map[j-1][i] == '0' || map[j-1][i] == 'c' || map[j-1][i] == 'e')//down
					{
						map[j-1][i] = 'p';
						scratch(map,j-1 , i);
					}
				if (map[j][i+1] == '0' || map[j][i+1] == 'c' || map[j][i+1] == 'e')//r
					{
						map[j][i+1] = 'p';
						scratch(map,j , i+1);
					}
				if (map[j][i-1] == '0' || map[j][i-1] == 'c' || map[j][i-1] == 'e')//l
					{
						map[j][i-1] = 'p';
						scratch(map, j, i-1);
					}
			}
		j++;
	// }
	//int j,i;
	j = 0;
	printf("\n==========\n");

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