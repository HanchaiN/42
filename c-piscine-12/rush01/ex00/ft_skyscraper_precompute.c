/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_precompute.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:40:22 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/18 14:12:33 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int	*get_perm(int size, int ind)
{
	int	*perm;
	int	i;
	int	j;
	int	temp;

	perm = (int *) malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		perm[i] = ind % (size - i);
		ind /= (size - i);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + perm[i];
		temp = perm[i];
		perm[j] = perm[i];
		perm[i] = perm[j];
	}
	return (perm);
}

void	precompute_columns(int size)
{
	(void) size;
}

int	generate_possible_columns(t_column *col)
{
	col->possible_size = -1;
	col->possible = (int *)malloc(0);
	return (1);
}
