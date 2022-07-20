/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:29:13 by blaurent          #+#    #+#             */
/*   Updated: 2022/07/20 14:41:55 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "mylib/includes/ft_printf.h"
# include "mylib/includes/libft.h"
# include "mylib/includes/gnl.h"

typedef struct s_pst
{
	int	x;
	int	y;
}		t_pst;

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	void	*img[7];
	t_pst	size;
	t_pst	pos;
	int		dir;
	int		e;
	int		c;
	int		p;
}			t_data;

enum
{
	B1,
	B2,
	E,
	F,
	P1,
	P2,
	W
};

void	quit(t_data *d, char *err);
void	initd(t_data *d);
void	initimg(t_data *d);
int		keypress(int k, t_data *d);

char	**getmap(char *fmap, t_data *d);
int		checkmap(char **map, t_data *d);
void	elem(char c, t_data *d);
int		badmap(char **map, t_pst pos, t_data *d);

int		movepos(int k, t_data *d);
void	mvleft(t_data *d);
void	mvup(t_data *d);
void	mvdown(t_data *d);
void	mvright(t_data *d);
void	mvimg(t_data *d);

void	initmap(t_data *d);
void	rndframe(t_data *d);
void	putimg(t_data *d, int spr, int x, int y);
void	putmapimg(t_data *d, t_pst p);

#endif