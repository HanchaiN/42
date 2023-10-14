/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:39:17 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 13:09:13 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf_conversion.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	printf_conversion_d(va_list ap)
{
	char	*str;
	int		len;

	str = ft_itoa(va_arg(ap, int));
	ft_putstr_fd(str, STDOUT_FILENO);
	len = ft_strlen(str);
	free(str);
	return (len);
}
