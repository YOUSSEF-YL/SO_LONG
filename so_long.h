/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:59:50 by ybachar           #+#    #+#             */
/*   Updated: 2022/12/23 20:21:08 by ybachar          ###   ########.fr       */
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

char ** get_map(int fd);
int check_liens_l(char **map);
int map_lines(char* map);
int check_walls(char **map);
int check_pathe(char **map);
void scratch(char ** map,int i , int j);
int map_req(char ** map);
struct map{
  int x;
  int y;
  char* exit;
  char* player;
  char* empty;
  char* wall;
  char* collectible;
};

struct vars{
  int i;
  int j;
  int p;
	int e;
	int c;
  char** map;
};
typedef struct map map;

#endif