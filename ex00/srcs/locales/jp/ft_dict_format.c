/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:18:34 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 15:12:22 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "ft_dict.h"
#define MYRIAD (10000)

const char	*g_default_dict = "./numbers.jp.dict";

static int	_put_number_digit(unsigned int digit, unsigned int digit_value,
		const char *path, t_buffer *buffer)
{
	if (((digit_value == 100 && (digit == 3 || digit == 6 || digit == 8))
			|| (digit_value == 1000 && (digit == 3 || digit == 8)))
		&& !ft_put_value(digit * digit_value, path, buffer))
		return (0);
	if (ft_put_value(digit, path, buffer))
		return (1);
	ft_buffer_putstr("-", buffer);
	if (ft_put_value(digit_value, path, buffer))
		return (1);
	return (0);
}

static int	_put_number_group(unsigned int nbr, const char *path,
		t_buffer *buffer)
{
	int	digit;
	int	digit_value;

	digit_value = MYRIAD / 10;
	while (digit_value)
	{
		digit = (nbr / digit_value) % 10;
		if (!digit)
		{
			digit_value /= 10;
			continue ;
		}
		if (_put_number_digit(digit, digit_value, path, buffer))
			return (1);
		if (nbr % digit_value)
			ft_buffer_putstr(" ", buffer);
		digit_value /= 10;
	}
	return (0);
}

static unsigned int	_get_group_digit_value(unsigned int nbr)
{
	unsigned int	digit_value;

	digit_value = 1;
	nbr /= MYRIAD;
	while (nbr > 0)
	{
		nbr /= MYRIAD;
		digit_value *= MYRIAD;
	}
	return (digit_value);
}

int	ft_put_number(unsigned int nbr, const char *path, t_buffer *buffer)
{
	unsigned int	digit_value;
	unsigned int	group_value;

	if (nbr == 0)
		return (ft_put_value(nbr, path, buffer));
	digit_value = _get_group_digit_value(nbr);
	while (1)
	{
		group_value = (nbr / digit_value) % MYRIAD;
		if (_put_number_group(group_value, path, buffer))
			return (1);
		if (digit_value <= 1)
			break ;
		if (group_value)
		{
			ft_buffer_putstr("-", buffer);
			if (ft_put_value(digit_value, path, buffer))
				return (1);
		}
		if (nbr % digit_value)
			ft_buffer_putstr(", ", buffer);
		digit_value /= MYRIAD;
	}
	return (0);
}
