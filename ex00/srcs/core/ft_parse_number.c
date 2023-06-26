/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:37:11 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 22:30:16 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_dict.h"

unsigned int	ft_parse_number(char *str, int *error_flag)
{
	unsigned int	nbr;

	if (!str)
	{
		*error_flag |= 1;
		return (0);
	}
	while (ft_isspace(*str))
		str++;
	nbr = 0;
	if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (nbr >= 429496730 || (nbr >= 429496729 && *str > '5'))
		{
			*error_flag |= 1;
			return (0);
		}
		nbr *= 10;
		nbr += *str - '0';
		str++;
	}
	*error_flag |= (*str != '\0');
	return (nbr);
}
