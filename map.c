/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:35:20 by blaurent          #+#    #+#             */
/*   Updated: 2022/07/26 15:35:38 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**getmap(char *fmap, t_data *d)
{
	char	**map;
	char	*tmap;
	int		fd;

	fd = open(fmap, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmap = gnl(fd);
	close(fd);
	if (!tmap)
		return (NULL);
	map = ft_split(tmap, '\n');
	free(tmap);
	if (checkmap(map, d))
	{
		if (map)
			ft_freetab(map);
		return (NULL);
	}
	return (map);
}

int	checkmap(char **map, t_data *d)
{
	t_pst	pos;

	pos.x = 0;
	pos.y = 0;
	if (!map)
		return (-1);
	while (map[0][d->size.x])
		d->size.x++;
	while (map[d->size.y])
		d->size.y++;
	while (map[pos.y])
	{
		elem(map[pos.y][pos.x], d);
		if (!map[pos.y][pos.x])
		{
			if (badmap(map, pos, d))
				return (-1);
			pos.x = 0;
			pos.y++;
		}
		pos.x++;
	}
	if (d->e != 1 || d->p != 1 || d->c < 1)
		return (-1);
	return (0);
}

void	elem(char c, t_data *d)
{
	if (c == 'C')
		d->c++;
	else if (c == 'E')
		d->e++;
	else if (c == 'P')
		d->p++;
	else if (c != '\0' && c != '0' && c != '1')
		d->e = 10;
}

int	badmap(char **map, t_pst pos, t_data *d)
{
	int	i;

	i = 0;
	if (pos.x != d->size.x)
		return (-1);
	else if (pos.y == 0 || pos.y == d->size.y - 1)
	{
		while (i < pos.x)
		{
			if (map[pos.y][i++] != '1')
				return (-1);
		}
	}
	else if (map[pos.y][0] != '1' || map[pos.y][d->size.x - 1] != '1')
		return (-1);
	return (0);
}
