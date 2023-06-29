/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:15:33 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/09 09:27:08 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
	return ;
}

void	_putnbr(long nb)
{
	if (nb == 0)
		return ;
	_putnbr(nb / 10);
	ft_putchar('0' + nb % 10);
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
		_putnbr((long)nb);
	}
	else
	{
		ft_putchar('-');
		_putnbr(-(long)nb);
	}
	return ;
}
