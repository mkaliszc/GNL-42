/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:23:09 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/10/22 02:32:41 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*read_line(int fd)
{
	static char	*buffer;

	while (ft_strchr(buffer, '\n'))
		read(fd, buffer, BUFFER_SIZE);
	
	
}

char	*get_next_line(int fd)
{
	char	*buf;

	if (fd < 0)
		return (NULL);
	buf = read_line(fd);
}
