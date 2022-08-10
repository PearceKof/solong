/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:28:29 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/10 17:02:26 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit(t_data *d, char *err)
{
	int	i;

	if (d)
	{
		i = 0;
		while (i < 7)
			mlx_destroy_image(d->mlx, d->img[i++]);
		mlx_destroy_window(d->mlx, d->win);
		ft_freetab(d->map);
	}
	if (err)
	{
		ft_fprintf(STDERR_FILENO, "ERROR\n%s\n", err);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

static void	init_d(t_data *d)
{
	d->dir = 0;
	d->e = 0;
	d->c = 0;
	d->p = 0;
	d->size.x = 0;
	d->size.y = 0;
}

static void	init_img(t_data *d)
{
	int	w;
	int	h;

	d->img[0] = mlx_xpm_file_to_image(d->mlx, "sprites/button1.xpm", &w, &h);
	d->img[1] = mlx_xpm_file_to_image(d->mlx, "sprites/button2.xpm", &w, &h);
	d->img[2] = mlx_xpm_file_to_image(d->mlx, "sprites/exit.xpm", &w, &h);
	d->img[3] = mlx_xpm_file_to_image(d->mlx, "sprites/floor.xpm", &w, &h);
	d->img[4] = mlx_xpm_file_to_image(d->mlx, "sprites/p1.xpm", &w, &h);
	d->img[5] = mlx_xpm_file_to_image(d->mlx, "sprites/p2.xpm", &w, &h);
	d->img[6] = mlx_xpm_file_to_image(d->mlx, "sprites/wall.xpm", &w, &h);
}

static int	keypress(int k, t_data *d)
{
	static int	count = 1;

	if (move_pos(k, d))
		return (1);
	ft_fprintf(STDIN_FILENO, "%d\n", count++);
	if (d->map[d->pos.y / 32][d->pos.x / 32] == 'E' && d->c == 0)
		quit(d, NULL);
	return (0);
}

int	main(int ag, char **av)
{
	t_data	d;

	if (ag != 2)
		quit(NULL, "Invalid argument");
	init_d(&d);
	d.map = get_map(av[1], &d);
	if (!d.map)
		quit(NULL, "Invalid map");
	if (!have_path(&d))
		quit(NULL, "No path to the exit");
	d.size.x *= 32;
	d.size.y *= 32;
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, d.size.x, d.size.y, "so_long");
	init_img(&d);
	init_map(&d);
	mlx_key_hook(d.win, keypress, &d);
	mlx_loop(d.mlx);
}
