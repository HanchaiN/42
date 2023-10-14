/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:42:32 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 13:09:24 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "printf_conversion.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, STDOUT_FILENO);
			ret++;
		}
		else
			ret += printf_conversion(*(++format), ap);
		format++;
	}
	va_end(ap);
	return (ret);
}
