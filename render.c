/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:38:54 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/11 13:37:32 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
0 B1 b1.xpm
1 B2 b2.xpm
2 E exit.xpm
3 F floor.xpm
4 P1 p1.xpm
5 P2 p2.xpm
6 W wall.xpm
7 null
*/
static void	put_map_img(t_data *d, t_pst p)
{
	if (d->map[p.y][p.x] == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->img[W], p.x * 32, p.y * 32);
	else if (d->map[p.y][p.x] == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->img[F], p.x * 32, p.y * 32);
	else if (d->map[p.y][p.x] == 'C')
		mlx_put_image_to_window(d->mlx, d->win, d->img[B1], p.x * 32, p.y * 32);
	else if (d->map[p.y][p.x] == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->img[E], p.x * 32, p.y * 32);
}

void	render_map(t_data *d)
{
	t_pst	p;

	p.x = 0;
	p.y = 0;
	while (d->map[p.y])
	{
		while (d->map[p.y][p.x])
		{
			if (d->map[p.y][p.x] == 'P')
			{
				d->map[p.y][p.x] = '0';
				d->pos.x = p.x * 32;
				d->pos.y = p.y * 32;
			}
			put_map_img(d, p);
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img[P2], d->pos.x, d->pos.y);
}

void	replace_img(t_data *d)
{
	if (d->map[d->pos.y / 32][(d->pos.x / 32)] == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->img[F], d->pos.x, d->pos.y);
	else if (d->map[d->pos.y / 32][(d->pos.x / 32)] == 'X')
		mlx_put_image_to_window(d->mlx, d->win, d->img[B2], d->pos.x, d->pos.y);
	else if (d->map[d->pos.y / 32][(d->pos.x / 32)] == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->img[E], d->pos.x, d->pos.y);
}
