/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:59:50 by ybachar           #+#    #+#             */
/*   Updated: 2022/12/26 20:21:00 by ybachar          ###   ########.fr       */
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
} t_intvars;

typedef struct t_map{
  int x;
  int y;
  char* exit;
  char* player;
  char* empty;
  char* wall;
  char* collectible;
} t_map;

char ** get_map(int fd);
int check_liens_l(char **map);
int map_lines(char* map);
int check_walls(char **map);
int check_pathe(char **map);
void scratch(char ** map,int i , int j);
int map_req(char ** map);
int	key_hook(char ** map,int keycode);
void draw_to_win(t_vars var,char ** map);
//t_va  get_ppos (char ** map);




typedef struct map map;



#endif