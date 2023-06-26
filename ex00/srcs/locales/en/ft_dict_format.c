/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:18:34 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 21:08:39 by kkomasat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_buffer.h"
#include "ft_dict.h"
#define THOUSAND (1000)

const char *g_default_dict = "./numbers.en.dict";

static int    _put_number_group(unsigned int nbr, const char *path, t_buffer *buffer)
{
    if (nbr == 0)
        return (0);
    if (nbr / 100)
    {
        if (ft_put_number(nbr / 100, path, buffer))
            return (1);
        ft_buffer_putstr(" ", buffer);
        if (ft_put_number(100, path, buffer))
            return (1);
        if (nbr % 100)
            ft_buffer_putstr(" and ", buffer);
    }
    if ((nbr % 100) / 10 == 1)
        return (ft_put_value(nbr % 100, path, buffer));
    if (ft_put_value((nbr % 100 / 10) * 10, path, buffer))
        return (1);
    if ((nbr % 100) / 10 && nbr % 10)
        ft_buffer_putstr("-", buffer);
    if (ft_put_value(nbr % 10, path, buffer))
        return (1);
    return (0);
}

static unsigned int	_get_group_digit_value(unsigned int nbr)
{
	unsigned int	digit_value;

	digit_value = 1;
	nbr /= THOUSAND;
	while (nbr > 0)
	{
		nbr /= THOUSAND;
		digit_value *= THOUSAND;
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
		group_value = (nbr / digit_value) % THOUSAND;
		if (_put_number_group(group_value, path, buffer))
			return (1);
		if (digit_value <= 1)
			break ;
		if (group_value)
		{
			ft_buffer_putstr(" ", buffer);
			if (ft_put_value(digit_value, path, buffer))
				return (1);
		}
		if (nbr % digit_value)
			ft_buffer_putstr(" ", buffer);
		digit_value /= THOUSAND;
	}
	return (0);
}