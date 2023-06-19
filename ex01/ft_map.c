/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:24:06 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/19 13:21:09 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*ret;

	ret = (int *) malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		ret[i] = (*f)(tab[i]);
		i++;
	}
	return (ret);
}
