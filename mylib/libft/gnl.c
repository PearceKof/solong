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

char	*ft_readfile(char *file, int fd)
{
	char	*tmp;
	int		end;

	end = 1;
	tmp = malloc(BUFFER_SIZE * sizeof(char));
	if (!tmp)
		return (NULL);
	while (end != 0)
	{
		end = read(fd, tmp, BUFFER_SIZE);
		if (end == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[end] = '\0';
		file = ft_joinfile(file, tmp);
		if (!file)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
	return (file);
}

char	*ft_joinfile(char *s1, char *s2)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	free(s1);
	return (str);
}
