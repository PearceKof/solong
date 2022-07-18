/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:38:54 by blaurent          #+#    #+#             */
/*   Updated: 2022/07/18 15:58:12 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putimg(t_data *d, char *spr, int x, int y)
{
	int		img_width;
	int		img_height;

	d->img = mlx_xpm_file_to_image(d->mlx, spr, &img_width, &img_height);
	mlx_put_image_to_window(d->mlx, d->win, d->img, x, y);
}

void	mvimg(t_data *d)
{
	if (d->map[d->pos.y / 32][(d->pos.x / 32)] == '0')
		ft_putimg(d, "./sprites/floor.xpm", d->pos.x, d->pos.y);
	else if (d->map[d->pos.y / 32][(d->pos.x / 32)] == 'X')
		ft_putimg(d, "./sprites/button2.xpm", d->pos.x, d->pos.y);
	else if (d->map[d->pos.y / 32][(d->pos.x / 32)] == 'E')
		ft_putimg(d, "./sprites/exit.xpm", d->pos.x, d->pos.y);
}

void	ft_putmapimg(t_data *d, t_pst p)
{
			if (d->map[p.y][p.x] == '1')
				ft_putimg(d, "./sprites/wall.xpm", p.x * 32, p.y * 32);
			else if (d->map[p.y][p.x] == '0')
				ft_putimg(d, "./sprites/floor.xpm", p.x * 32, p.y * 32);
			else if (d->map[p.y][p.x] == 'C')
				ft_putimg(d, "./sprites/button1.xpm", p.x * 32, p.y * 32);
			else if (d->map[p.y][p.x] == 'E')
				ft_putimg(d, "./sprites/exit.xpm", p.x * 32, p.y * 32);
}

void	ft_initmap(t_data *d)
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
			ft_putmapimg(d, p);
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
	ft_putimg(d, "./sprites/p1.xpm", d->pos.x, d->pos.y);
	mlx_put_image_to_window(d->mlx, d->win, d->img, p.x * 32, p.y * 32);
}
