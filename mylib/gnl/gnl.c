/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:20:52 by blaurent          #+#    #+#             */
/*   Updated: 2022/06/03 17:20:52 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gnl.h"

char	*gnl(int fd)
{
	static char	*file;

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	file = ft_readfile(file, fd);
	if (!file)
		return (NULL);
	return (file);
}

char	*cooler_gnl(int fd)
{
	static char	*file[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	file[fd] = ft_readfile(file[fd], fd);
	if (!file[fd])
		return (NULL);
	line = ft_cpyline(file[fd]);
	file[fd] = ft_nxtline(file[fd]);
	return (line);
}
