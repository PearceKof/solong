/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:28:29 by blaurent          #+#    #+#             */
/*   Updated: 2022/06/27 17:11:03 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_quit(t_data *d)
{
	ft_freetab(d->map);
	system("leaks a.out");
	exit(0);
}

int	ft_movepos(int k, t_data *d)
{
	if (k == 53)
		ft_quit(d);
	if (k == 0 && d->map[d->pos.y / 32][(d->pos.x / 32) - 1] != '1')
	{
		d->pos.x -= 32;
		d->dir = 1;
	}
	else if (k == 1 && d->map[(d->pos.y / 32) + 1][d->pos.x / 32] != '1')
		d->pos.y += 32;
	else if (k == 2 && d->map[d->pos.y / 32][(d->pos.x / 32) + 1] != '1')
	{
		d->pos.x += 32;
		d->dir = 0;
	}
	else if (k == 13 && d->map[(d->pos.y / 32) - 1][d->pos.x / 32] != '1')
		d->pos.y -= 32;
	else
		return (1);
	return (0);
}

int	ft_keypress(int k, t_data *d)
{
	if (ft_movepos(k, d))
		return (0);
	if (d->map[d->pos.y / 32][d->pos.x / 32] == 'C')
	{
		d->map[d->pos.y / 32][d->pos.x / 32] = 'X';
		d->c--;
	}
	if (d->map[d->pos.y / 32][d->pos.x / 32] == 'E' && d->c == 0)
		ft_quit(d);
	ft_printf("%d\n", d->count++);
	return (0);
}

void	ft_initd(t_data *d)
{
	d->dir = 0;
	d->size.x = 0;
	d->size.y = 0;
	d->count = 0;
	d->e = 0;
	d->c = 0;
	d->p = 0;
}

int	main(int ag, char **av)
{
	t_data	d;

	ft_initd(&d);
	d.map = ft_getmap(av[1], &d);
	if (!d.map)
		return (-1);
	d.size.x *= 32;
	d.size.y *= 32;
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, d.size.x, d.size.y, "so_long");
	d.img = mlx_new_image(d.mlx, d.size.x, d.size.y);
	mlx_loop_hook(d.mlx, ft_rndframe, &d);
	mlx_key_hook(d.win, ft_keypress, &d);
	mlx_loop(d.mlx);
	return (0);
}
