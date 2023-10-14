/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:39:17 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 13:09:06 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf_conversion.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	printf_conversion_s(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", STDOUT_FILENO);
		return (6);
	}
	ft_putstr_fd(str, STDOUT_FILENO);
	return (ft_strlen(str));
}
