/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:53:24 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/17 15:53:16 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*mlx_win;
	void	*relative_path;
	int		img_width;
	int		img_height;
	char	**map;
}	t_vars;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*get_ligne(char *str);
char	*get_extra(char *str);
int		ft_strlen(char *str);
void	freeall(t_vars *vars);
int		check_path_e(char **map, int j, int i);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif