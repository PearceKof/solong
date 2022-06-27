/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:35:03 by blaurent          #+#    #+#             */
/*   Updated: 2022/06/01 14:35:42 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *str, const char *chr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (chr[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		if (str[i] == chr[j])
		{
			while (str[i + j] == chr[j])
			{
				j++;
				if (chr[j] == '\0')
					return ((char *)str + i);
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
