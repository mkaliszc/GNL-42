/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:51:55 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/10/22 02:24:59 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i += 1;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t		index;
	char		*ptr;

	index = 0;
	ptr = (char *)str;
	while (index < (ft_strlen(str) + 1))
	{
		if (ptr[index] == (char)c)
		{
			return (&ptr[index]);
		}
		index++;
	}
	return (NULL);
}