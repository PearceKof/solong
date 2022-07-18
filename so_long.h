/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:29:13 by blaurent          #+#    #+#             */
/*   Updated: 2022/07/18 15:49:01 by blaurent         ###   ########.fr       */
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
# include "mylib/includes/libft.h"
# include "mylib/includes/gnl.h"
# include "mylib/includes/ft_printf.h"

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
	void	*img;
	t_pst	size;
	t_pst	pos;
	int		dir;
	int		e;
	int		c;
	int		p;
}			t_data;

void	ft_initmap(t_data *d);
char	**ft_getmap(char *fmap, t_data *d);
void	ft_elem(char c, t_data *d);
int		ft_checkmap(char **map, t_data *d);

int		ft_movepos(int k, t_data *d);
void	mvleft(t_data *d);
void	mvup(t_data *d);
void	mvdown(t_data *d);
void	mvright(t_data *d);

void	mvimg(t_data *d);
void	ft_quit(t_data *d, char *err);
void	ft_initd(t_data *d);
void	ft_rndframe(t_data *d);
void	ft_putimg(t_data *d, char *spr, int x, int y);
int		ft_keypress(int k, t_data *d);

#endif