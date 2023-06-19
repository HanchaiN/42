/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:56:18 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/19 14:03:04 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	cmp;
	int	cmp_;

	cmp_ = 0;
	i = 1;
	while (i < length)
	{
		cmp = (*f)(tab[i - 1], tab[i]);
		if (cmp != 0)
		{
			if (cmp == 0)
				cmp_ = cmp_;
			else if (cmp_ * cmp >= 0)
				cmp_ = cmp;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
