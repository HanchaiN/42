/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:10:25 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/26 15:07:08 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fileio.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>

/** Read content of a file
 * @param path path to the file
 * @return content of the whole file (must be freed).
*/
char	*ft_read_file(char *path)
{
	char	*buffer;
	int		fileno;
	size_t	size;

	size = ft_get_file_size(fileno);
	fileno = open(path, O_RDONLY);
	buffer = (char *) malloc(size * sizeof(char));
	if (fileno < 0 || read(fileno, buffer, size) != size)
	{
		free(buffer);
		ft_putstr("Failed to read content\n");
		return (NULL);
	}
	close(fileno);
	return (buffer);
}
