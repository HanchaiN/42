/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:37:43 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 22:07:33 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

unsigned int	manage_character(char *str, unsigned int *ptr)
{
	int	index;
	int	sign;

	sign = 1;
	index = 0;
	while (ft_isspace(str[index]))
		index++;
	while (str[index] && (str[index] == '-' || str[index] == '+'))
	{
		if (str[index] == '-')
		{
			sign *= -1;
		}
		index++;
	}
	*ptr = index;
	return (sign);
}

unsigned int	ft_atoi_uint(char *str)
{
	unsigned int	sign;
	unsigned int	input_number;
	unsigned int	index;

	sign = manage_character(str, &index);
	input_number = 0;
	while (str[index] != '\0' && '0' <= str[index] && str[index] <= '9' )
	{
		input_number = 10 * input_number + (str[index] - '0');
		++index;
	}
	return (input_number * sign);
}
