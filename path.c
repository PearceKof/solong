/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:00:37 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/11 16:01:09 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**dup_map(t_data d)
{
	char	**new_map;
	int		i;

	new_map = malloc((d.size.y + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (d.map[i])
	{
		new_map[i] = ft_strdup(d.map[i]);
		if (!new_map[i])
		{
			while (new_map[--i])
				free(new_map[i]);
			free(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

static int	check_path(char **map, int y, int x, int *still_a_path)
{
	if (map[y][x] != '1' && map[y][x] != 'P')
	{
		if (map[y][x] == 'E')
			return (1);
		*still_a_path = 1;
		map[y][x] = 'P';
	}
	return (0);
}

static int	search_nxt_path(char **map, t_pst check, int *still_a_path)
{
	if (map[check.y][check.x] == 'P')
	{
		if (check_path(map, check.y - 1, check.x, still_a_path))
			return (1);
		if (check_path(map, check.y + 1, check.x, still_a_path))
			return (1);
		if (check_path(map, check.y, check.x - 1, still_a_path))
			return (1);
		if (check_path(map, check.y, check.x + 1, still_a_path))
			return (1);
	}
	return (0);
}

static int	path_finding(char **map)
{
	int		still_a_path;
	t_pst	check;

	still_a_path = 1;
	while (still_a_path)
	{
		still_a_path = 0;
		check.x = 0;
		check.y = 0;
		while (map[check.y])
		{
			while (map[check.y][check.x])
			{
				if (search_nxt_path(map, check, &still_a_path))
					return (1);
				check.x++;
			}
			check.x = 0;
			check.y++;
		}
	}
	return (0);
}

int	have_path(t_data *d)
{
	char	**searching_map;
	int		ret;

	searching_map = dup_map(*d);
	if (!searching_map)
	{
		ft_freetab(d->map);
		error(NULL, "Failed to duplicate map");
	}
	ret = path_finding(searching_map);
	ft_freetab (searching_map);
	return (ret);
}
