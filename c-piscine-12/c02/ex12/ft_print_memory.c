/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 08:47:53 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/15 14:36:19 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define LINE_LEN 16

void	_write_hex(unsigned long long value, int count)
{
	const char		digits[] = "0123456789abcdef";

	if (count == 0)
		return ;
	_write_hex(value / 16, count - 1);
	write(STDOUT_FILENO, &digits[value % 16], 1);
	return ;
}

void	_write_char(char ch)
{
	if (' ' <= ch && ch <= '~')
	{
		write(STDOUT_FILENO, &ch, 1);
	}
	else
	{
		write(STDOUT_FILENO, ".", 1);
	}
	return ;
}

void	_print_hex_line(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (j < LINE_LEN)
	{
		if (i >= size)
			write(STDOUT_FILENO, "  ", 2);
		else
			_write_hex(*(unsigned long long *) addr, 2);
		if (j % 2 == 1)
			write(STDOUT_FILENO, " ", 1);
		i++;
		j++;
		addr++;
	}
	return ;
}

void	_print_str_line(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (j < LINE_LEN)
	{
		if (i >= size)
			write(STDOUT_FILENO, " ", 1);
		else
			_write_char(*(char *)addr);
		i++;
		j++;
		addr++;
	}
	return ;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		_write_hex((unsigned long long)(addr + i), 16);
		write(STDOUT_FILENO, ": ", 2);
		_print_hex_line(addr + i, size - i);
		_print_str_line(addr + i, size - i);
		write(STDOUT_FILENO, "\n", 1);
		i += LINE_LEN;
	}
	return (addr);
}
