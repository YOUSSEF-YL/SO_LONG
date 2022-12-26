/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:59:50 by ybachar           #+#    #+#             */
/*   Updated: 2022/12/26 14:50:49 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "get_next_line.h"





typedef struct	s_vars {
	void	*mlx;
	void	*win;
  void	*mlx;
	void	*mlx_win;
  void   *relative_path;
	int		img_width ;
	int		img_height ;
  char** map;
}				t_vars;
typedef struct vars{
  int i;
  int j;
  int p;
	int e;
	int c;
} t_va;

char ** get_map(int fd);
int check_liens_l(char **map);
int map_lines(char* map);
int check_walls(char **map);
int check_pathe(char **map);
void scratch(char ** map,int i , int j);
int map_req(char ** map);
int	key_hook(char ** map,int keycode);
t_va  get_ppos (char ** map);

struct map{
  int x;
  int y;
  char* exit;
  char* player;
  char* empty;
  char* wall;
  char* collectible;
};


typedef struct map map;



#endif