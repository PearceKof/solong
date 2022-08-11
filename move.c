/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:01:24 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/11 16:00:09 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mvleft(t_data *d)
{
	replace_img(d);
	d->pos.x -= 32;
	d->dir = 1;
	if (d->map[d->pos.y / 32][d->pos.x / 32] == 'C')
	{
		d->c--;
		d->map[d->pos.y / 32][d->pos.x / 32] = 'X';
		mlx_put_image_to_window(d->mlx, d->win, d->img[B2], d->pos.x, d->pos.y);
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img[P1], d->pos.x, d->pos.y);
}

static void	mvup(t_data *d)
{
	replace_img(d);
	d->pos.y -= 32;
	if (d->map[d->pos.y / 32][d->pos.x / 32] == 'C')
	{
		d->c--;
		d->map[d->pos.y / 32][d->pos.x / 32] = 'X';
		mlx_put_image_to_window(d->mlx, d->win, d->img[B2], d->pos.x, d->pos.y);
	}
	if (d->dir == 1)
		mlx_put_image_to_window(d->mlx, d->win, d->img[P1], d->pos.x, d->pos.y);
	else
		mlx_put_image_to_window(d->mlx, d->win, d->img[P2], d->pos.x, d->pos.y);
}

static void	mvdown(t_data *d)
{
	replace_img(d);
	d->pos.y += 32;
	if (d->map[d->pos.y / 32][d->pos.x / 32] == 'C')
	{
		d->c--;
		d->map[d->pos.y / 32][d->pos.x / 32] = 'X';
		mlx_put_image_to_window(d->mlx, d->win, d->img[B2], d->pos.x, d->pos.y);
	}
	if (d->dir == 1)
		mlx_put_image_to_window(d->mlx, d->win, d->img[P1], d->pos.x, d->pos.y);
	else
		mlx_put_image_to_window(d->mlx, d->win, d->img[P2], d->pos.x, d->pos.y);
}

static void	mvright(t_data *d)
{
	replace_img(d);
	d->pos.x += 32;
	d->dir = 0;
	if (d->map[d->pos.y / 32][d->pos.x / 32] == 'C')
	{
		d->c--;
		d->map[d->pos.y / 32][d->pos.x / 32] = 'X';
		mlx_put_image_to_window(d->mlx, d->win, d->img[B2], d->pos.x, d->pos.y);
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img[P2], d->pos.x, d->pos.y);
}

int	move_pos(int k, t_data *d)
{
	if (k == 53)
		quit(d);
	if (k == 0 && d->map[d->pos.y / 32][(d->pos.x / 32) - 1] != '1')
		mvleft(d);
	else if (k == 1 && d->map[(d->pos.y / 32) + 1][d->pos.x / 32] != '1')
		mvdown(d);
	else if (k == 2 && d->map[d->pos.y / 32][(d->pos.x / 32) + 1] != '1')
		mvright(d);
	else if (k == 13 && d->map[(d->pos.y / 32) - 1][d->pos.x / 32] != '1')
		mvup(d);
	else
		return (1);
	return (0);
}
