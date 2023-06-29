/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_ascii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:02:32 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/29 09:53:19 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include <fcntl.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>

void	_format_ascii_hex(int count, char *buffer)
{
	int	j;

	j = 0;
	while (j < count)
	{
		if (j % 8 == 0)
			ft_putchar(' ', STDOUT_FILENO);
		ft_putchar(' ', STDOUT_FILENO);
		ft_write_hex((unsigned char) buffer[j], 2, STDOUT_FILENO);
		j++;
	}
	while (j < 16)
	{
		if (j % 8 == 0)
			ft_putchar(' ', STDOUT_FILENO);
		ft_putchar(' ', STDOUT_FILENO);
		ft_putstr("  ", STDOUT_FILENO);
		j++;
	}
}

void	_format_ascii_ascii(int count, char *buffer)
{
	int	j;

	j = 0;
	while (j < count)
	{
		ft_write_char(buffer[j], STDOUT_FILENO);
		j++;
	}
}

void	ft_format_ascii(unsigned long long index, int count, char *buffer)
{
	ft_write_hex(index - count, 8, STDOUT_FILENO);
	_format_ascii_hex(count, buffer);
	ft_putstr("  |", STDOUT_FILENO);
	_format_ascii_ascii(count, buffer);
	ft_putstr("|\n", STDOUT_FILENO);
}
