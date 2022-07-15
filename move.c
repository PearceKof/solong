/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:01:24 by blaurent          #+#    #+#             */
/*   Updated: 2022/07/15 15:30:09 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_movepos(int k, t_data *d)
{
	if (k == 53)
		ft_quit(d, NULL);
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
	if (d->map[d->pos.y / 32][d->pos.x / 32] == 'E' && d->c == 0)
		ft_quit(d, NULL);
	return (0);
}

void	mvleft(t_data *d)
{
	mvimg(d);
	d->pos.x -= 32;
	d->dir = 1;
	if (d->map[d->pos.y / 32][d->pos.x / 32] == 'C')
	{
		d->c--;
		d->map[d->pos.y / 32][d->pos.x / 32] = 'X';
		mlx_destroy_image(d->mlx, d->img);
		ft_putimg(d, "./sprites/button2.xpm", d->pos.x, d->pos.y);
	}
	mlx_destroy_image(d->mlx, d->img);
	ft_putimg(d, "./sprites/p1.xpm", d->pos.x, d->pos.y);
}

void	mvup(t_data *d)
{
	mvimg(d);
	d->pos.y -= 32;
	if (d->map[d->pos.y / 32][d->pos.x / 32] == 'C')
	{
		d->c--;
		d->map[d->pos.y / 32][d->pos.x / 32] = 'X';
		mlx_destroy_image(d->mlx, d->img);
		ft_putimg(d, "./sprites/button2.xpm", d->pos.x, d->pos.y);
	}
	mlx_destroy_image(d->mlx, d->img);
	if (d->dir == 1)
		ft_putimg(d, "./sprites/p1.xpm", d->pos.x, d->pos.y);
	else
		ft_putimg(d, "./sprites/p2.xpm", d->pos.x, d->pos.y);
}

void	mvdown(t_data *d)
{
	mvimg(d);
	d->pos.y += 32;
	if (d->map[d->pos.y / 32][d->pos.x / 32] == 'C')
	{
		d->c--;
		d->map[d->pos.y / 32][d->pos.x / 32] = 'X';
		mlx_destroy_image(d->mlx, d->img);
		ft_putimg(d, "./sprites/button2.xpm", d->pos.x, d->pos.y);
	}
	mlx_destroy_image(d->mlx, d->img);
	if (d->dir == 1)
		ft_putimg(d, "./sprites/p1.xpm", d->pos.x, d->pos.y);
	else
		ft_putimg(d, "./sprites/p2.xpm", d->pos.x, d->pos.y);
}

void	mvright(t_data *d)
{
	mvimg(d);
	d->pos.x += 32;
	d->dir = 0;
	if (d->map[d->pos.y / 32][d->pos.x / 32] == 'C')
	{
		d->c--;
		d->map[d->pos.y / 32][d->pos.x / 32] = 'X';
		mlx_destroy_image(d->mlx, d->img);
		ft_putimg(d, "./sprites/button2.xpm", d->pos.x, d->pos.y);
	}
	mlx_destroy_image(d->mlx, d->img);
	ft_putimg(d, "./sprites/p2.xpm", d->pos.x, d->pos.y);
}
