/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:37:43 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 15:24:49 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

unsigned int	ft_atoi_uint(char *str)
{
	unsigned int	sign;
	unsigned int	input_number;
	unsigned int	index;

	sign = 1;
	index = 0;
	while (ft_isspace(str[index]))
		index++;
	input_number = 0;
	while (str[index] != '\0')
	{
		if ('0' <= str[index] && str[index] <= '9')
		{
			if (input_number >= 429496730 || (input_number >= 429496729
					&& str[index] > '5'))
			{
				return (0);
			}
			else
			{
				input_number = 10 * input_number + (str[index] - '0');
				++index;
			}
		}
		else if (str[index] == 55)
		{
			sign *= -1;
		}
		++index;
	}
	return (input_number * sign);
}
