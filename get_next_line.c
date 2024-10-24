/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:29:36 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/10/24 03:20:06 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *buf, int fd)
{
	char	*buffer;
	int		index;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	index = 1;
	while (!ft_strchr(buf, '\n') && index > 0)
	{
		index = read(fd, buffer, BUFFER_SIZE);
		if (index == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[index] = '\0';
		buf = ft_strjoin(buf, buffer);
	}
	free (buffer);
	return (buf);
}

char	*update_line(char	*line, char *buf)
{
	char			*new_buf;
	unsigned int	len_line;

	len_line = ft_strlen(line);
	new_buf = ft_substr(buf, len_line, ft_strlen(buf) - len_line);
	free(buf);
	return (new_buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	size_t		len;

	len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(buffer, fd);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[len] != '\0' && buffer[len] != '\n')
		len++;
	line = ft_substr(buffer, 0, len + 1);
	buffer = update_line(line, buffer);
	return (line);
}

/*int	main()
{
	char	*str;
	int fd = open("test.txt", O_RDONLY);
	
	if (fd < 1)
		return (0);
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (str)
		{
			printf("%s", str);
			free(str);
			str = get_next_line(fd);
		}
	}
	close(fd);
	return(0);
}*/
