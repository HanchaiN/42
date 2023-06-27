/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:14:07 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/27 10:14:17 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include <stdlib.h>
#include <unistd.h>

/** Read a line from a file
 * @param fileno file descriptor
 * @return null-terminated string malloc(3)ed by the call
*/
char	*ft_read_line(int fileno)
{
	t_buffer	*buffer;
	int			read_count;
	char		ch;
	char		*str;

	read_count = read(fileno, &ch, 1);
	if (read_count <= 0)
		return (NULL);
	buffer = ft_buffer_new(1);
	while (read_count > 0 && ch != '\n')
	{
		ft_buffer_putchar(ch, buffer);
		read_count = read(fileno, &ch, 1);
	}
	str = ft_buffer_strdup(buffer);
	ft_buffer_free(buffer);
	return (str);
}
