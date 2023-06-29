/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:48:51 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/13 17:10:25 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	lower;
	int	upper;
	int	mid;

	if (nb < 0)
		return (0);
	lower = 0;
	upper = 46341;
	while (lower != upper - 1)
	{
		mid = (lower + upper) / 2;
		if (mid * mid <= nb)
			lower = mid;
		else
			upper = mid;
	}
	if (lower * lower == nb)
		return (lower);
	return (0);
}
