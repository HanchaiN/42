/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:02:32 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/24 19:07:07 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include <fcntl.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>

void	ft_format_hex(unsigned long long index, int count, char *buffer)
{
	int	j;

	ft_write_hex(index - count, 7, STDOUT_FILENO);
	ft_putchar(' ', STDOUT_FILENO);
	j = 0;
	while (j < count)
	{
		if (j)
			ft_putchar(' ', STDOUT_FILENO);
		ft_write_hex((unsigned char) buffer[j], 2, STDOUT_FILENO);
		j++;
	}
	while (j < 16)
	{
		if (j)
			ft_putchar(' ', STDOUT_FILENO);
		ft_putstr("  ", STDOUT_FILENO);
		j++;
	}
	ft_putchar('\n', STDOUT_FILENO);
}
