/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:39:17 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 13:09:04 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf_conversion.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static size_t	get_length(unsigned int n)
{
	if (n >= 10)
		return (get_length(n / 10) + 1);
	else
		return (1);
}

static char	*putnbr_buffer(unsigned int n, char *buff)
{
	const char	lookup[10] = "0123456789";

	if (n >= 10)
	{
		buff = putnbr_buffer(n / 10, buff);
		buff = putnbr_buffer(n % 10, buff);
	}
	else
		*(buff++) = lookup[n];
	return (buff);
}

static char	*itoa_uint(unsigned int n)
{
	char	*buff;

	buff = malloc((get_length(n) + 1) * sizeof(char));
	if (!buff)
		return (buff);
	*putnbr_buffer(n, buff) = '\0';
	return (buff);
}

int	printf_conversion_u(va_list ap)
{
	char	*str;
	int		len;

	str = itoa_uint(va_arg(ap, unsigned int));
	ft_putstr_fd(str, STDOUT_FILENO);
	len = ft_strlen(str);
	free(str);
	return (len);
}
