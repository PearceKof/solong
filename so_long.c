/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:28:29 by blaurent          #+#    #+#             */
/*   Updated: 2022/07/18 16:29:02 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_quit(t_data *d, char *err)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	if (d)
		ft_freetab(d->map);
	if (err)
	{
		ft_printf("ERROR\n%s", err);
		system("leaks so_long");
		exit(EXIT_FAILURE);
	}
	system("leaks so_long");
	exit(EXIT_SUCCESS);
}

void	ft_initd(t_data *d)
{
	d->dir = 0;
	d->e = 0;
	d->c = 0;
	d->p = 0;
	d->size.x = 0;
	d->size.y = 0;
}

int	ft_keypress(int k, t_data *d)
{
	static int	count = 1;

	if (ft_movepos(k, d))
		return (0);
	ft_printf("%d\n", count++);
	return (0);
}

int	main(int ag, char **av)
{
	t_data	d;

	if (ag != 2)
	{
		ft_putstr_fd("ERROR\nInvalid argument\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ft_initd(&d);
	d.map = ft_getmap(av[1], &d);
	if (!d.map)
	{
		ft_putstr_fd("ERROR\nInvalid map\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	d.size.x *= 32;
	d.size.y *= 32;
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, d.size.x, d.size.y, "so_long");
	d.img = mlx_new_image(d.mlx, d.size.x, d.size.y);
	ft_initmap(&d);
	mlx_key_hook(d.win, ft_keypress, &d);
	mlx_loop(d.mlx);
}
