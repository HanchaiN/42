/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 08:15:31 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/12 11:46:31 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	const char	digits[] = "0123456789abcdef";

	while (*str != '\0')
	{
		if (0x20 <= *str && *str <= 0x7e)
		{
			write(STDOUT_FILENO, str, 1);
		}
		else
		{
			write(STDOUT_FILENO, "\\", 1);
			write(STDOUT_FILENO, &digits[(*str / 16) % 16], 1);
			write(STDOUT_FILENO, &digits[*str % 16], 1);
		}
		str++;
	}
	return ;
}
