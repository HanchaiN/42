/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:27:17 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/27 16:46:45 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	strjoin_realloc_clear(char **s1, char *s2, size_t s2len)
{
	char	*temp;

	if (*s1 == NULL)
	{
		ft_bzero(s2, s2len * sizeof(char));
		return ;
	}
	temp = *s1;
	*s1 = (char *)malloc((ft_strlen(temp) + s2len + 1) * sizeof(char));
	if (*s1)
	{
		ft_memmove(*s1, temp, ft_strlen(temp));
		ft_memmove(*s1 + ft_strlen(temp), s2, s2len);
		ft_bzero(s2, s2len * sizeof(char));
		(*s1)[ft_strlen(temp) + s2len] = '\0';
	}
	free(temp);
}

static void	memshift(void *block, ssize_t shift, size_t block_size)
{
	ft_memmove(block, block + shift, block_size - shift);
	ft_bzero((void *)(block + block_size - shift), shift);
}

static size_t	strlen_lim(char *str, size_t maxlen)
{
	char	*end;

	end = ft_memchr(str, '\0', maxlen);
	if (!end)
		return (maxlen);
	return (end - str);
}

static void	get_next_line_(int fd, char **line, char *buffer)
{
	char	*endl;
	ssize_t	read_size;

	read_size = strlen_lim(buffer, BUFFER_SIZE);
	while (1)
	{
		if (buffer[0] == '\0')
		{
			read_size = read(fd, buffer, BUFFER_SIZE);
			if (read_size == 0 && (*line)[0])
				return ;
			if (read_size <= 0)
			{
				free(*line);
				*line = NULL;
				return ;
			}
		}
		endl = ft_memchr(buffer, '\n', (size_t)read_size);
		if (endl)
			break ;
		strjoin_realloc_clear(line, buffer, (size_t)read_size);
	}
	strjoin_realloc_clear(line, buffer, endl - buffer + 1);
	memshift(buffer, endl - buffer + 1, BUFFER_SIZE * sizeof(char));
}

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	line = get_empty_string();
	get_next_line_(fd, &line, buffer[fd]);
	return (line);
}
