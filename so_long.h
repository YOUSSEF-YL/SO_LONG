/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:59:50 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/08 13:34:41 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "get_next_line.h"
#include "ft_printf/ft_printf.h"

typedef struct s_vars
{
	void *mlx;
	void *win;
	void *mlx_win;
	void *relative_path;
	int img_width;
	int img_height;
	char **map;
} t_vars;
typedef struct vars
{
	int i;
	int j;
	int p;
	int e;
	int c;
} t_intvars;

typedef struct t_map
{
	int x;
	int y;
	char *exit;
	char *player;
	char *empty;
	char *wall;
	char *collectible;
} t_map;

int move_to(t_vars *vars, int j, int i, t_intvars intvar, int c);
int is_map_valid(char **map);
int somthing(char **map);
int ft_exit(void);
int check_liens_l(char **map);
int map_lines(char *map);
int check_walls(char **map);
int map_req(char **map);
int key_hook(int keycode, t_vars *vars);
int check_map_compos(char **map);
char **get_map(int fd);
char **check_path(char **map, int j, int i);
void draw_to_win(t_vars var, char **map);
void printmap(char **map);
void put_bg(t_vars var);
t_intvars get_plyer_pos(char **map);


#endif