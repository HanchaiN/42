/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:10:25 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/27 10:14:19 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_fileio.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/** Read content of a file
 * @param path path to the file
 * @return null-terminated string malloc(3)ed by the call
*/
char	*ft_read_file(char *path)
{
	char	*buffer;
	int		fileno;
	size_t	size;
	ssize_t	read_size;

	size = ft_get_file_size(path);
	fileno = open(path, O_RDONLY);
	buffer = (char *) malloc(size * sizeof(char));
	read_size = read(fileno, buffer, size);
	if (fileno < 0 || read_size < 0 || (size_t) read_size != size)
	{
		free(buffer);
		ft_putstr("Failed to read content\n");
		return (NULL);
	}
	close(fileno);
	return (buffer);
}
