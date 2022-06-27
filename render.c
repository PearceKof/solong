/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:38:54 by blaurent          #+#    #+#             */
/*   Updated: 2022/06/27 14:51:26 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putimg(t_data *d, char *spr, int x, int y)
{
	int		img_width;
	int		img_height;

	d->img = mlx_xpm_file_to_image(d->mlx, spr, &img_width, &img_height);
	mlx_put_image_to_window(d->mlx, d->win, d->img, x, y);
	return (0);
}

int	ft_rndmap(t_data *d, t_pst p)
{
	if (d->map[p.y][p.x] == 'P')
	{
		d->map[p.y][p.x] = '0';
		d->pos.x = p.x * 32;
		d->pos.y = p.y * 32;
	}
	if (d->map[p.y][p.x] == '0')
		ft_putimg(d, "./sprites/floor1.xpm", p.x * 32, p.y * 32);
	else if (d->map[p.y][p.x] == '1')
		ft_putimg(d, "./sprites/wbm.xpm", p.x * 32, p.y * 32);
	else if (d->map[p.y][p.x] == 'C')
		ft_putimg(d, "./sprites/button1.xpm", p.x * 32, p.y * 32);
	else if (d->map[p.y][p.x] == 'X')
		ft_putimg(d, "./sprites/button2.xpm", p.x * 32, p.y * 32);
	else if (d->map[p.y][p.x] == 'E')
		ft_putimg(d, "./sprites/exit.xpm", p.x * 32, p.y * 32);
	return (0);
}

int	ft_rndframe(t_data *d)
{
	t_pst	p;

	p.x = 0;
	p.y = 0;
	while (d->map[p.y])
	{
		while (d->map[p.y][p.x])
		{
			ft_rndmap(d, p);
			p.x++;
		}
		p.x = 0;
		p.y++;
	}
	if (d->dir == 1)
		ft_putimg(d, "./sprites/p1.xpm", d->pos.x, d->pos.y);
	else
		ft_putimg(d, "./sprites/p2.xpm", d->pos.x, d->pos.y);
	return (0);
}
