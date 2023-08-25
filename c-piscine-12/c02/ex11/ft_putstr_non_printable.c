/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 08:15:31 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/15 14:35:28 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	const char		digits[] = "0123456789abcdef";
	unsigned char	ch;

	while (*str != '\0')
	{
		ch = *str;
		if (0x20 <= ch && ch <= 0x7e)
		{
			write(STDOUT_FILENO, &ch, 1);
		}
		else
		{
			write(STDOUT_FILENO, "\\", 1);
			write(STDOUT_FILENO, &digits[(ch / 16) % 16], 1);
			write(STDOUT_FILENO, &digits[ch % 16], 1);
		}
		str++;
	}
	return ;
}
