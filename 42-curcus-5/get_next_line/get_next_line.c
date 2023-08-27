/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:27:17 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/28 01:07:10 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	gnl_read_append(int fd, char **buffer, char **endl)
{
	ssize_t	read_size;
	char	*buff;

	*endl = ft_strchr(*buffer, '\n');
	if (*endl)
		return (1);
	read_size = ft_strlen(*buffer);
	*buffer = ft_realloc_inc(*buffer, read_size + BUFFER_SIZE + 1, read_size);
	buff = *buffer + read_size;
	if (!*buffer)
	{
		*endl = NULL;
		return (-1);
	}
	read_size = read(fd, buff, BUFFER_SIZE);
	if (read_size < 0)
		free(*buffer);
	if (read_size < 0)
		*buffer = NULL;
	if (read_size >= 0)
		buff[read_size] = '\0';
	*endl = ft_strchr(*buffer, '\n');
	if (!*endl)
		*endl = &buff[read_size - 1];
	return (read_size);
}

static void	get_next_line_io(int fd, char **line, char **buffer)
{
	char	*endl;
	ssize_t	read_size;

	while (1)
	{
		read_size = gnl_read_append(fd, buffer, &endl);
		if (read_size < 0 || (read_size == 0 && *buffer[0] == '\0'))
		{
			free(*line);
			*line = NULL;
			return ;
		}
		if ((endl && endl >= *buffer && *endl == '\n') || read_size == 0)
			break ;
	}
	read_size = ft_strlen(*line);
	*line = ft_realloc_inc(*line, read_size + endl - *buffer + 2, read_size);
	if (!*line)
		return ;
	ft_memmove(*line + read_size, *buffer, endl - *buffer + 1);
	(*line)[read_size + endl - *buffer + 1] = '\0';
	*buffer = ft_memmove(*buffer, endl + 1, ft_strlen(endl + 1) + 1);
}

static char	**gnl_get_buffer(int fd)
{
	static char	*buffer[OPEN_MAX];

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	return (&buffer[fd]);
}

void	gnl_clear_buffer(int fd)
{
	char	**buffer;

	if (fd < 0 || fd >= OPEN_MAX)
		return ;
	buffer = gnl_get_buffer(fd);
	free(*buffer);
	*buffer = NULL;
}

char	*get_next_line(int fd)
{
	char	*line[1];

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	line[0] = NULL;
	get_next_line_io(fd, &line[0], gnl_get_buffer(fd));
	if (!line[0])
		gnl_clear_buffer(fd);
	return (line[0]);
}
