/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:47:49 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/25 14:46:29 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <unistd.h>

int	ft_tail(int fileno, int byte_count)
{
	int		i;
	int		read_count;
	char	*buffer;

	if (byte_count <= 0)
		return (0);
	buffer = (char *) malloc(byte_count * sizeof(char));
	i = 0;
	read_count = read(fileno, buffer + i % byte_count, 1);
	while (read_count > 0)
	{
		i++;
		read_count = read(fileno, buffer + i % byte_count, 1);
	}
	if (i > byte_count)
		write(STDOUT_FILENO,
			buffer + i % byte_count,
			byte_count - i % byte_count);
	write(STDOUT_FILENO, buffer, i % byte_count);
	free(buffer);
	if (read_count < 0)
		return (errno);
	return (0);
}

int	ft_tail_file(char *pathname, int byte_count, int show_header)
{
	int	fileno;
	int	status;

	fileno = open(pathname, O_RDONLY);
	if (fileno < 0)
		return (errno);
	if (show_header)
		ft_display_header(pathname);
	status = ft_tail(fileno, byte_count);
	close(fileno);
	return (status);
}

int	ft_tail_stdin(int byte_count)
{
	int	status;

	status = ft_tail(STDIN_FILENO, byte_count);
	return (status);
}
