/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:46:04 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/20 16:15:52 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

int	ft_add(int value1, int value2, int *ret)
{
	*ret = value1 + value2;
	return (1);
}

int	ft_sub(int value1, int value2, int *ret)
{
	*ret = value1 - value2;
	return (1);
}

int	ft_div(int value1, int value2, int *ret)
{
	if (value2 == 0)
	{
		ft_putstr("Stop: division by zero\n");
		return (0);
	}
	*ret = value1 / value2;
	return (1);
}

int	ft_mul(int value1, int value2, int *ret)
{
	*ret = value1 * value2;
	return (1);
}

int	ft_mod(int value1, int value2, int *ret)
{
	if (value2 == 0)
	{
		ft_putstr("Stop: modulo by zero\n");
		return (0);
	}
	*ret = value1 % value2;
	return (1);
}
