/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_formatter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 08:47:53 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/24 19:09:22 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include <string.h>
#include <unistd.h>

void	ft_write_hex(
	unsigned long long value,
	unsigned int min_count,
	int fileno)
{
	const char	digits[] = "0123456789abcdef";

	if (value == 0 && min_count == 0)
		return ;
	if (min_count > 0)
		min_count--;
	ft_write_hex(value / 16, min_count, fileno);
	ft_putchar(digits[value % 16], fileno);
	return ;
}

void	ft_write_char(char ch, int fileno)
{
	if (' ' <= ch && ch <= '~')
		ft_putchar(ch, fileno);
	else
		ft_putchar('.', fileno);
}

void	ft_format_error(char *program_name, char *pathname, int status)
{
	if (!status)
		return ;
	ft_putstr(program_name, STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(pathname, STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(strerror(status), STDERR_FILENO);
	ft_putstr("\n", STDERR_FILENO);
}