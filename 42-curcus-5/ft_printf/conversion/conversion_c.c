/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:39:17 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 13:09:14 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf_conversion.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	printf_conversion_c(va_list ap)
{
	ft_putchar_fd((char)va_arg(ap, int), STDOUT_FILENO);
	return (1);
}
