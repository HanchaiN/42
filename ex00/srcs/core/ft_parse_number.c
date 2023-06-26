/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:37:11 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 15:14:04 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"
#include <stdlib.h>

unsigned int	handle_number(char string[], int *error_flag,
				unsigned int *input_number, int *i)
{
	while (string[*i] != '\0')
	{
		if ('0' <= string[*i] && string[*i] <= '9')
		{
			if (*input_number >= 429496730 || \
						(*input_number >= 429496729 && string[*i] > '5'))
			{
				*error_flag = 1;
				return (0);
			}
			else
			{
				*input_number = 10 * *input_number + (string[*i] - 48);
				++*i;
			}
		}
		else
		{
			*error_flag = 1;
			return (0);
		}
	}
	return (*input_number);
}

unsigned int	ft_parse_number(char string[], int *error_flag)
{
	unsigned int	input_number;
	int				i;

	input_number = 0;
	i = 0;
	if (string == NULL)
	{
		*error_flag = 1;
		return (0);
	}
	input_number = handle_number(string, error_flag, &input_number, &i);
	return (input_number);
}
