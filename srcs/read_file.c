/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:10:25 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/26 11:10:27 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "useful_funcs.h"

//This function gets file descriptor
int	get_fd(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	return (fd);
}

//gets the size of file by given file descriptor
ssize_t	get_size(int fd)
{
	char	buffer[1024];
	ssize_t	chunk_sz;
	ssize_t	total_sz;

	chunk_sz = 1;
	total_sz = chunk_sz;
	while (chunk_sz > 0)
	{
		chunk_sz = read(fd, buffer, sizeof(buffer));
		if (chunk_sz == -1)
			return (-1);
		total_sz = total_sz + chunk_sz;
	}
	close(fd);
	return (total_sz - 1);
}

//Return the read file written in array of chars
// MUST BE FREED AFTER USAGE
char	*get_content(char *path)
{
	char	*content;
	int		fd;
	ssize_t	size;

	fd = get_fd(path);
	if (fd == -1)
	{
		ft_putstr("Failed to open the file\n");
		return (NULL);
	}
	size = get_size(fd);
	fd = get_fd(path);
	content = (char *) malloc(size);
	if (read(fd, content, size) != size)
	{
		ft_putstr("Failed to read content\n");
		return (NULL);
	}
	close(fd);
	return (content);
}
