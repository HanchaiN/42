/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:39:17 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 11:42:42 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static size_t	get_length(unsigned int n)
{
	if (n >= 16)
		return (get_length(n / 16) + 1);
	else
		return (1);
}

static char	*putnbr_buffer(unsigned int n, char *buff)
{
	const char	lookup[16] = "0123456789ABCDEF";

	if (n >= 16)
	{
		buff = putnbr_buffer(n / 16, buff);
		buff = putnbr_buffer(n % 16, buff);
	}
	else
		*(buff++) = lookup[n];
	return (buff);
}

static char	*itoa_hex(unsigned int n)
{
	char	*buff;

	buff = malloc((get_length(n) + 1) * sizeof(char));
	if (!buff)
		return (buff);
	*putnbr_buffer(n, buff) = '\0';
	return (buff);
}

int	printf_conversion_x_upper(va_list ap)
{
	char	*str;
	int		len;

	str = itoa_hex(va_arg(ap, unsigned int));
	ft_putstr_fd(str, STDOUT_FILENO);
	len = ft_strlen(str);
	free(str);
	return (len);
}
