/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:43:56 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 14:44:13 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

unsigned int	ft_min(unsigned int *tab, unsigned int count)
{
	unsigned int	i;
	unsigned int	val;

	val = tab[0];
	i = 1;
	while (i < count)
	{
		if (tab[i] < val)
			val = tab[i];
		i++;
	}
	return (val);
}
