/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:15:33 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/16 09:54:16 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
	return ;
}

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
