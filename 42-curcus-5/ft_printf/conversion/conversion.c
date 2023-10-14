/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:53:47 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 14:45:19 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf_conversion.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	printf_conversion(char command, va_list ap)
{
	if (command == 'c')
		return (printf_conversion_c(ap));
	if (command == 's')
		return (printf_conversion_s(ap));
	if (command == 'p')
		return (printf_conversion_p(ap));
	if (command == 'd')
		return (printf_conversion_d(ap));
	if (command == 'i')
		return (printf_conversion_i(ap));
	if (command == 'u')
		return (printf_conversion_u(ap));
	if (command == 'x')
		return (printf_conversion_x_lower(ap));
	if (command == 'X')
		return (printf_conversion_x_upper(ap));
	if (command == '%')
	{
		ft_putchar_fd('%', STDOUT_FILENO);
		return (1);
	}
	return (0);
}
