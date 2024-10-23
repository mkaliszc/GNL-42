/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:23:09 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/10/23 02:49:54 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *buf, int fd)
{
	char	*buffer;
	size_t	index;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
		
	while (ft_strchr(buffer, '\n') == 0)
	{
		index = read(fd, buffer, BUFFER_SIZE);
		if (index < 1)
		{
			free(buffer);
			return (NULL);
		}
		buf = ft_strjoin(buf, buffer);
	}
	free (buffer);
	return (buf);
}

/* static char	*update_line(char	*line)
{
	
} */

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*line;
	size_t		len;

	len = 0;
	if (fd < 0)
		return (NULL);
	buf = read_line(buf, fd);
	while (buf[len] != '\0' || buf[len] != '\n')
		len++;
	line = ft_substr(buf, 0, len);
	//buf = updated_line(line);
	return (line);
}

int	main()
{
	int fd = open("test.txt", O_RDONLY);
	
	if (fd < 1)
		return (0);
	printf("%s", get_next_line(fd));
	return(0);
}
