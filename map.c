/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:35:20 by blaurent          #+#    #+#             */
/*   Updated: 2022/07/05 15:55:02 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_badmap(char **map, t_pst pos, t_data *d)
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

void	ft_elem(char c, t_data *d)
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

int	ft_checkmap(char **map, t_data *d)
{
	t_pst	pos;

	if (!map)
		return (-1);
	while (map[0][d->size.x])
		d->size.x++;
	while (map[d->size.y])
		d->size.y++;
	while (map[pos.y])
	{
		ft_elem(map[pos.y][pos.x], d);
		if (!map[pos.y][pos.x])
		{
			if (ft_badmap(map, pos, d))
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

char	**ft_getmap(char *fmap, t_data *d)
{
	char	**tmap;
	char	*map;
	int		fd;

	fd = open(fmap, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = ft_calloc(1, sizeof(char));
	if (!map || ft_read(fd, &map))
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	tmap = ft_split(map, '\n');
	free(map);
	if (ft_checkmap(tmap, d))
	{
		free(tmap);
		ft_printf("ERROR\nInvalid map");
		return (NULL);
	}
	return (tmap);
}

int	ft_read(int fd, char **file)
{
	char	*tmp;
	int		end;

	tmp = malloc(30000 * sizeof(char));
	if (!tmp)
		return (-1);
	end = read(fd, tmp, 30000);
	if (end == -1)
	{
		free (tmp);
		return (-1);
	}
	tmp[end] = '\0';
	*file = ft_joinfile(*file, tmp);
	if (!*file)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (0);
}
