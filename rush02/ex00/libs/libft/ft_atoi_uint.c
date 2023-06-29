/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:37:43 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 19:11:44 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

unsigned int	ft_atoi_uint(char *str)
{
	unsigned int	nbr;

	while (ft_isspace(*str))
		str++;
	nbr = 0;
	if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - '0';
		str++;
	}
	return (nbr);
}
