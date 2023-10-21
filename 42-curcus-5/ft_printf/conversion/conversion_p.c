/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:39:17 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/22 01:32:39 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf_conversion.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static size_t	get_length(size_t n)
{
	if (n >= 16)
		return (get_length(n / 16) + 1);
	else
		return (1);
}

static char	*putnbr_buffer(size_t n, char *buff)
{
	const char	lookup[16] = "0123456789abcdef";

	if (n >= 16)
	{
		buff = putnbr_buffer(n / 16, buff);
		buff = putnbr_buffer(n % 16, buff);
	}
	else
		*(buff++) = lookup[n];
	return (buff);
}

static char	*itoa_sizet(size_t n)
{
	char	*buff;

	buff = malloc((get_length(n) + 1) * sizeof(char));
	if (!buff)
		return (buff);
	*putnbr_buffer(n, buff) = '\0';
	return (buff);
}

int	printf_conversion_p(va_list ap)
{
	void	*val;
	char	*str;
	int		len;

	val = va_arg(ap, void *);
	if (val == NULL)
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		return (5);
	}
	str = itoa_sizet((size_t)val);
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	len = ft_strlen(str) + 2;
	free(str);
	return (len);
}
