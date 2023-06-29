/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:50:26 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/14 09:25:45 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb == 2 || nb == 3)
		return (1);
	if (nb < 2 || nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i * i <= nb && i * i > 0)
	{
		if (
			nb % i == 0
			|| nb % (i + 2) == 0
		)
			return (0);
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb <= 2)
		return (2);
	if (nb <= 3)
		return (3);
	i = (nb / 6) * 6 - 1;
	while (i > 0)
	{
		if (i >= nb && ft_is_prime(i))
			return (i);
		if (i + 2 >= nb && ft_is_prime(i + 2))
			return (i + 2);
		i += 6;
	}
	return (2);
}
