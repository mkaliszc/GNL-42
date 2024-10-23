/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:51:55 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/10/23 02:49:35 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i += 1;
	return (i);
}

char	*ft_strchr(char *str, int c)
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
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
	{
		ptr = malloc(sizeof(char));
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*return_chain;

	i = 0;
	j = 0;
	return_chain = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (return_chain == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		return_chain[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		return_chain[i + j] = s2[j];
		j++;
	}
	return_chain[i + j] = '\0';
	return (return_chain);
}