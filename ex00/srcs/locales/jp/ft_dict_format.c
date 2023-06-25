/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:18:34 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/24 15:03:32 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "ft_dict.h"
#define MYRIAD (10000)

const char	*g_default_dict = "./numbers.jp.dict";

int	ft_put_number_group(unsigned int nbr, char *path, t_buffer *buffer)
{
	int	digit;
	int	digit_value;

	if (nbr == 0)
		return (0);
	digit_value = MYRIAD / 10;
	while (digit_value)
	{
		digit = (nbr / digit_value) % 10;
		if (!digit || ft_put_value(digit * digit_value, path, buffer))
		{
			digit_value /= 10;
			continue ;
		}
		if (!ft_put_value(digit, path, buffer))
			return (-1);
		ft_buffer_putstr("-", buffer);
		if (!ft_put_value(digit_value, path, buffer))
			return (-1);
		if (nbr % digit_value)
			ft_buffer_putstr(" ", buffer);
		digit_value /= 10;
	}
	return (1);
}

unsigned int	ft_get_group_value(unsigned int nbr)
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

int	ft_put_number(unsigned int nbr, char *path, t_buffer *buffer)
{
	unsigned int	digit_value;
	int				status;

	if (nbr == 0)
		return (ft_put_value(nbr, path, buffer));
	digit_value = ft_get_group_value(nbr);
	while (1)
	{
		status = ft_put_number_group((nbr / digit_value) % MYRIAD,
				path, buffer);
		if (status < 0)
			return (0);
		if (status && digit_value > 1)
		{
			ft_buffer_putstr("-", buffer);
			if (!ft_put_value(digit_value, path, buffer))
				return (0);
		}
		if (digit_value / MYRIAD && nbr % digit_value)
			ft_buffer_putstr(", ", buffer);
		else
			break ;
		digit_value /= MYRIAD;
	}
	return (1);
}
