/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:59:44 by ybachar           #+#    #+#             */
/*   Updated: 2022/12/30 16:28:21 by ybachar          ###   ########.fr       */
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
	return(i );
}

char **get_map(int lines)
{
	char **map;
	int i ;
	i = 0;

	map = (char **)malloc (map_lines("map.txt") * sizeof(char *));
	int fd;
	fd = open("map.txt", O_RDONLY);
	

	while (i <= lines-1 )
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	map[map_lines("map.txt")] = 0;
	return(map);
}

void apptowindow(void* mlx, void *mlx_win,int img_width,int img_height,char* img_path,int x, int y)
{
	void *xpm = mlx_xpm_file_to_image(mlx, img_path, &img_width, &img_height);
	
	mlx_put_image_to_window(mlx,mlx_win, xpm,x,y);
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
			if (map[intvar.j][intvar.i] == '1')
				apptowindow(var.mlx, var.mlx_win, var.img_width,var.img_height,"assets/wall.xpm",map_util.x,map_util.y);
			// else if (map[intvar.j][intvar.i] == '0')
			// 	 apptowindow(var.mlx,var.mlx_win,var.img_width,var.img_height,"assets/wall.xpm",map_util.x,map_util.y);
			else if (map[intvar.j][intvar.i] == 'C')
				apptowindow(var.mlx,var.mlx_win,var.img_width,var.img_height,"assets/collectible.xpm",map_util.x,map_util.y);
			else if (map[intvar.j][intvar.i] == 'E')
				apptowindow(var.mlx,var.mlx_win,var.img_width,var.img_height,"assets/exit.xpm",map_util.x,map_util.y);
			else if (map[intvar.j][intvar.i] == 'P')
				apptowindow(var.mlx,var.mlx_win,var.img_width,var.img_height,"assets/player.xpm",map_util.x,map_util.y);
			intvar.i++;
			map_util.x = map_util.x + 50;
		}	
		map_util.x = 0;
		map_util.y = map_util.y + 50;
		intvar.j++;
	}
}

// int	key_hook(int keycode, t_vars *vars)
// {
// 	 printf("%d\n",keycode);
	
// 	return (1);
// }

int	main(void)
{
	t_vars var;
	
	// int		img_width = 1700;
	// int		img_height = 1700;

    var.mlx = mlx_init();
	//void *img = mlx_new_image(mlx, img_width, img_height);
	var.mlx_win = mlx_new_window(var.mlx, 1500, 800, "So_long");
	void *xpm = mlx_xpm_file_to_image(var.mlx,"assets/bg.xpm", &var.img_width, &var.img_height);
	
	mlx_put_image_to_window(var.mlx,var.mlx_win, xpm,0,0);
   
   
	
	var.map = (char **)malloc (map_lines("map.txt") * sizeof(char *));


	var.map = get_map(map_lines("map.txt"));
	
	int fd = open("map.txt", O_RDONLY); 
	
	
	draw_to_win(var,var.map);

	mlx_key_hook(var.mlx_win, &key_hook, &var);
	
	mlx_loop(var.mlx);
	
	
	
}



 




//gcc  -o mlx so_long.c  -lmlx -framework OpenGL -framework AppKit
//gcc so_long.c  -lmlx -framework OpenGL -framework AppKit

