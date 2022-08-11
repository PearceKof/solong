/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:29:13 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/11 13:37:50 by blaurent         ###   ########.fr       */
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

char	**get_map(char *fmap, t_data *d);
void	quit(t_data *d, char *err);
void	replace_img(t_data *d);
void	render_map(t_data *d);
int		move_pos(int k, t_data *d);
int		have_path(t_data *d);

#endif