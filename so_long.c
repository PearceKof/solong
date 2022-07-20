/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:28:29 by blaurent          #+#    #+#             */
/*   Updated: 2022/07/20 13:40:31 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ag, char **av)
{
	t_data	d;

	if (ag != 2)
		quit(NULL, "Invalid argument\n");
	initd(&d);
	d.map = getmap(av[1], &d);
	if (!d.map)
		quit(NULL, "Invalid map\n");
	d.size.x *= 32;
	d.size.y *= 32;
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, d.size.x, d.size.y, "so_long");
	d.img = mlx_new_image(d.mlx, d.size.x, d.size.y);
	initmap(&d);
	mlx_key_hook(d.win, keypress, &d);
	mlx_loop(d.mlx);
}

void	quit(t_data *d, char *err)
{
	if (d)
	{
		mlx_destroy_image(d->mlx, d->img);
		mlx_destroy_window(d->mlx, d->win);
		ft_freetab(d->map);
	}
	if (err)
	{
		ft_fprintf(STDERR_FILENO, "ERROR\n%s\n", err);
		system("leaks so_long");
		exit(EXIT_FAILURE);
	}
	system("leaks so_long");
	exit(EXIT_SUCCESS);
}

void	initd(t_data *d)
{
	d->dir = 0;
	d->e = 0;
	d->c = 0;
	d->p = 0;
	d->size.x = 0;
	d->size.y = 0;
}

int	keypress(int k, t_data *d)
{
	static int	count = 1;

	if (movepos(k, d))
		return (0);
	ft_fprintf(STDIN_FILENO, "%d\n", count++);
	return (0);
}
