/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:15:33 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/20 15:52:49 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

void	_putnbr(int nb)
{
	if (nb == 0)
		return ;
	_putnbr(nb / 10);
	if (nb > 0)
		ft_putchar('0' + nb % 10);
	else
		ft_putchar('0' - nb % 10);
	return ;
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		ft_putchar('0');
	}
	else if (nb > 0)
	{
		_putnbr(nb);
	}
	else
	{
		ft_putchar('-');
		_putnbr(nb);
	}
	return ;
}
