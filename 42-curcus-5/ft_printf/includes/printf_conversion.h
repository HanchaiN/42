/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:39:58 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 13:08:52 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_CONVERSION_H
# define PRINTF_CONVERSION_H
# include <stdarg.h>

int	printf_conversion_c(va_list ap);
int	printf_conversion_s(va_list ap);
int	printf_conversion_p(va_list ap);
int	printf_conversion_d(va_list ap);
int	printf_conversion_i(va_list ap);
int	printf_conversion_u(va_list ap);
int	printf_conversion_x_lower(va_list ap);
int	printf_conversion_x_upper(va_list ap);
int	printf_conversion(char command, va_list ap);

#endif
