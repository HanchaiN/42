/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:01:06 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/24 19:27:48 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include <fcntl.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>

int	_get_fileno(char ***argv, char *program_name, int *fileno)
{
	int	ret;

	ret = 0;
	while (**argv)
	{
		*fileno = open(**argv, O_RDONLY);
		if (*fileno < 0)
		{
			ft_format_error(program_name, **argv, errno);
			ret = 1;
		}
		(*argv)++;
		if (*fileno >= 0)
			return (ret);
	}
	*fileno = -2;
	return (ret);
}

int	_read(int *fileno, char *buffer, unsigned long long *ptr)
{
	int	read_count;

	read_count = read(*fileno, buffer + (*ptr) % 16, 16 - (*ptr) % 16);
	if (read_count > 0)
		*ptr += read_count;
	else
		*fileno = -1;
	if (read_count < 0)
		return (errno);
	return (0);
}

int	_read_and_update(unsigned long long *ptr,
		int *is_printed, char *buffer, int *fileno)
{
	if (*ptr % 16 || *is_printed)
	{
		_read(fileno, buffer, ptr);
		*is_printed &= (fileno < 0);
		return (0);
	}
	*is_printed = 1;
	return (1);
}

void	_format_footer(unsigned long long ptr)
{
	ft_write_hex(ptr, 7, STDOUT_FILENO);
	ft_putchar('\n', STDOUT_FILENO);
}

int	ft_hexdump(char **argv, char *program_name,
		void (*format)(unsigned long long, int, char *))
{
	int					fileno;
	char				buffer[16];
	unsigned long long	ptr;
	int					ret;
	int					is_printed;

	ret = 0;
	ptr = 0;
	fileno = -1;
	if (!*argv)
		fileno = STDIN_FILENO;
	is_printed = 1;
	while (fileno != -2)
	{
		if (fileno < 0)
			ret |= _get_fileno(&argv, program_name, &fileno);
		if (fileno > 0 && _read_and_update(&ptr, &is_printed, buffer, &fileno))
			(*format)(ptr, 16, buffer);
	}
	if (!is_printed && ptr % 16)
		(*format)(ptr, ptr % 16, buffer);
	if (ptr)
		_format_footer(ptr);
	return (ret);
}
