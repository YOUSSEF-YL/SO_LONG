/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:59:44 by ybachar           #+#    #+#             */
/*   Updated: 2022/12/26 14:56:07 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "so_long.h"



// char **get_map(int fd)
// {
	
// }

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

// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("%d\n",keycode);
// 	return (0);
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
	int i ;
	int j ;
	j = 0;
	i = 0;

	var.map = get_map(map_lines("map.txt"));
	
	int fd = open("map.txt", O_RDONLY); 
	
	//printf("%d",map_lines("map.txt"));
	//printf("%d",check_pathe(map));
	//scratch(map,13,1);

	// printf("%d",map_req( map));
	int index_y;
	int index_x;
	index_y = 0;
	index_x = 0;
	while (var.map[j])
	{
		i = 0;
		while (var.map[j][i])
		{
			if (var.map[j][i] == '1')
			{
				apptowindow(var.mlx, var.mlx_win, var.img_width,var.img_height,"assets/wall.xpm",index_x,index_y);
				
			}
			else if (var.map[j][i] == '0')
			{
				//apptowindow(mlx,mlx_win,img_width,img_height,"assets/wall.xpm",index_x,index_y);
			}
			else if (var.map[j][i] == 'C')
			{
				apptowindow(var.mlx,var.mlx_win,var.img_width,var.img_height,"assets/wall.xpm",index_x,index_y);
			}
			else if (var.map[j][i] == 'E')
			{
				apptowindow(var.mlx,var.mlx_win,var.img_width,var.img_height,"assets/wall.xpm",index_x,index_y);
			}
			else if (var.map[j][i] == 'P')
			{
				apptowindow(var.mlx,var.mlx_win,var.img_width,var.img_height,"assets/player.xpm",index_x,index_y);
			}
			
			i++;
			index_x = index_x + 50;
		}	

		index_x =0;
		index_y = index_y + 50;
		//printf("%s",map[j]);
		j++;
	}
	 mlx_loop(var.mlx);
	// t_vars	vars;

	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	// mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_loop(vars.mlx);
}



 




//gcc  -o mlx so_long.c  -lmlx -framework OpenGL -framework AppKit
//gcc so_long.c  -lmlx -framework OpenGL -framework AppKit

