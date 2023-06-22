/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:47:49 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/22 11:06:34 by hnonpras         ###   ########.fr       */
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

int	ft_tail_file(char *pathname, int byte_count,
	int show_header, char *program_name)
{
	int	fileno;
	int	status;

	fileno = open(pathname, O_RDONLY);
	if (fileno < 0)
	{
		ft_display_error_errno(program_name, pathname, errno);
		return (1);
	}
	if (show_header)
		ft_display_header(pathname);
	status = ft_tail(fileno, byte_count);
	close(fileno);
	ft_display_error_errno(program_name, pathname, status);
	return (status > 0);
}

int	ft_tail_stdin(int byte_count, char *program_name)
{
	int	status;

	status = ft_tail(STDIN_FILENO, byte_count);
	ft_display_error_errno(program_name, "-", status);
	return (status > 0);
}
