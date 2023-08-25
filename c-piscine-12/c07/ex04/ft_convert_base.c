/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:24:55 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/22 17:50:27 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	_strlen(char *str);
int	ft_atoi_base(char *str, char *base, int *nbr);

char	*_putnbr_base(int nb, int radix, char *base, char *str)
{
	if (nb == 0)
		return (str);
	str = _putnbr_base(nb / radix, radix, base, str);
	if (nb > 0)
		*str = base[nb % radix];
	else
		*str = base[-nb % radix];
	return (str + 1);
}

int	ft_putnbr_base(int nbr, char *base, char *str)
{
	int		radix;
	char	*str_;

	radix = _strlen(base);
	if (radix < 0)
		return (0);
	str_ = str;
	if (nbr == 0)
	{
		*str_ = base[0];
		str_++;
	}
	else if (nbr > 0)
	{
		str_ = _putnbr_base(nbr, radix, base, str_);
	}
	else
	{
		*str = '-';
		str_++;
		str_ = _putnbr_base(nbr, radix, base, str_);
	}
	*str_ = '\0';
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		nb;

	str = (char *)malloc(32 * sizeof(char));
	if (ft_atoi_base(nbr, base_from, &nb)
		&& ft_putnbr_base(nb, base_to, str))
		return (str);
	free(str);
	return (NULL);
}
