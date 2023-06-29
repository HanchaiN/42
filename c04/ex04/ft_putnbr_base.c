/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:24:55 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/15 12:04:30 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	_strlen(char *str)
{
	int		count;
	char	*ptr;

	count = 0;
	while (*str != '\0')
	{
		ptr = str + 1;
		while (*ptr != '\0')
		{
			if (*ptr == *str)
				return (-1);
			ptr++;
		}
		if (*str == '+' || *str == '-' || *str < ' ' || *str > '~')
			return (-1);
		str++;
		count++;
	}
	if (count < 2)
		return (-1);
	return (count);
}

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
	return ;
}

void	_putnbr_base(int nb, int radix, char *base)
{
	if (nb == 0)
		return ;
	_putnbr_base(nb / radix, radix, base);
	if (nb > 0)
		ft_putchar(base[nb % radix]);
	else
		ft_putchar(base[-nb % radix]);
	return ;
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	radix;

	radix = _strlen(base);
	if (radix < 0)
		return ;
	if (nbr == 0)
	{
		ft_putchar(base[0]);
	}
	else if (nbr > 0)
	{
		_putnbr_base(nbr, radix, base);
	}
	else
	{
		ft_putchar('-');
		_putnbr_base(nbr, radix, base);
	}
	return ;
}
