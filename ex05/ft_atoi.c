/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:14:54 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/20 16:03:34 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

int	is_whitespace(char c)
{
	return (
		c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' '
	);
}

int	ft_atoi(char *str)
{
	int	val;
	int	is_negative;

	while (is_whitespace(*str))
		str++;
	is_negative = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = !is_negative;
		str++;
	}
	val = 0;
	while ('0' <= *str && *str <= '9')
	{
		val *= 10;
		if (is_negative)
			val -= *str - '0';
		else
			val += *str - '0';
		str++;
	}
	return (val);
}
