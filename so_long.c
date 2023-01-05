/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:59:44 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/03 21:32:56 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "so_long.h"

int map_lines(char* map)
{
	char *str;
    int fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	int i ;
	i = 0;
	while(str)
	{
		i++;
		str = get_next_line(fd);
	}
	close(fd);
	free(str);
	return(i );
}

char **get_map(int lines)
{
	char **map;
	int i ;
	i = 0;

	map = (char **)malloc (map_lines("map.ber") * sizeof(char *));
	int fd;
	fd = open("map.ber", O_RDONLY);
	

	while (i <= lines-1 )
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	map[map_lines("map.ber")] = 0;
	return(map);
}

void apptowindow(void* mlx, void *mlx_win,int img_width,int img_height,char* img_path,int x, int y)
{
	char* path;
	path = "assets/green60.xpm";
	if (path != img_path)
	{
		void *xpm = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
		mlx_put_image_to_window(mlx,mlx_win, xpm,x,y);
	}
	void *xpm = mlx_xpm_file_to_image(mlx, img_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx,mlx_win, xpm,x,y);
	mlx_destroy_image(mlx,xpm);
}
void test(char **map,t_intvars intvar,t_vars var ,t_map	map_util)
{
	map_util.collectible = "assets/collectiblee.xpm";
	map_util.player = "assets/player.xpm";
	map_util.exit = "assets/door.xpm";
	map_util.wall = "";
	map_util.empty = "assets/green60.xpm";
	
	if (map[intvar.j][intvar.i] == '1')
				apptowindow(var.mlx, var.mlx_win, var.img_width,var.img_height,"assets/d.xpm",map_util.x,map_util.y);
			else if (map[intvar.j][intvar.i] == '0')
				 apptowindow(var.mlx,var.mlx_win,var.img_width,var.img_height,map_util.empty,map_util.x,map_util.y);
			else if (map[intvar.j][intvar.i] == 'C')
				apptowindow(var.mlx,var.mlx_win,var.img_width,var.img_height,map_util.collectible,map_util.x,map_util.y);
			else if (map[intvar.j][intvar.i] == 'E')
				apptowindow(var.mlx,var.mlx_win,var.img_width,var.img_height,map_util.exit,map_util.x,map_util.y);
			else if (map[intvar.j][intvar.i] == 'P')
				apptowindow(var.mlx,var.mlx_win,var.img_width,var.img_height,map_util.player,map_util.x,map_util.y);
}

void draw_to_win(t_vars var,char ** map)
{
	t_intvars intvar;
	t_map	map_util;

	map_util.y = 0;
	map_util.x = 0;
	
	intvar.j = 0;
	intvar.i = 0;
	while (map[intvar.j])
	{
		intvar.i = 0;
		while (map[intvar.j][intvar.i])
		{
			 test(map,intvar,var,map_util);
			intvar.i++;
			map_util.x = map_util.x + 60;
		}	
		map_util.x = 0;
		map_util.y = map_util.y + 60;
		intvar.j++;
	}
}


void put_bg(t_vars var)
{
	void *xpm = mlx_xpm_file_to_image(var.mlx,"assets/bg.xpm", &var.img_width, &var.img_height);
	mlx_put_image_to_window(var.mlx,var.mlx_win, xpm,0,0);
}

int ft_exit()
{
	exit(0);
}

int	main(void)
{
	t_vars var;
	t_intvars intvar;
	
	var.map = (char **)malloc (map_lines("map.ber") * sizeof(char *));
	var.map = get_map(map_lines("map.ber"));
	int fd;
	fd = open("map.ber", O_RDONLY); 

	intvar.i = 60 *(ft_strlen(var.map[0]) - 1);
	intvar.j = 60 *map_lines("map.ber");
	var.mlx = mlx_init();
	var.mlx_win = mlx_new_window(var.mlx,intvar.i,intvar.j, "So_long");
	//put_bg(var);
	draw_to_win(var,var.map);

	mlx_key_hook(var.mlx_win, key_hook, &var);
	mlx_hook(var.mlx_win,17, 0, ft_exit, &var);
	

	mlx_loop(var.mlx);

	//printf("%d",somthing(check_path(var.map,13,1)));
	

}

//gcc  -o mlx so_long.c  -lmlx -framework OpenGL -framework AppKit
//gcc so_long.c  -lmlx -framework OpenGL -framework AppKit

