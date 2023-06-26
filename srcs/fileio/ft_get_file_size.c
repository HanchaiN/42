/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:10:25 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/26 15:07:00 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fileio.h"
#include <fcntl.h>
#include <sys/types.h>

/** Get file size
 * @param path path to the file
 * @return size of the file (in bytes)
*/
size_t	ft_get_file_size(char *path)
{
	int		fileno;
	char	buffer[1024];
	ssize_t	read_size;
	size_t	file_size;

	fileno = open(path, O_RDONLY);
	if (fileno < 0)
		return (0);
	read_size = 1;
	file_size = 0;
	while (read_size > 0)
	{
		read_size = read(fileno, buffer, sizeof(buffer));
		if (read_size < 0)
		{
			close(fileno);
			return (-1);
		}
		file_size += read_size;
	}
	close(fileno);
	return (file_size);
}
