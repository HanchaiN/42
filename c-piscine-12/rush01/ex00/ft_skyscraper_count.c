/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:40:22 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/18 14:46:43 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int	get_count_left(int *column, int n)
{
	int	i;
	int	max_height;
	int	count;

	count = 0;
	i = 0;
	while (i < n)
	{
		if (column[i] > max_height)
		{
			max_height = column[i];
			count++;
		}
		i++;
	}
	return (count);
}

t_range	get_count_range_left(int index, const t_column *column)
{
	t_range	count_range;
	int		max_height;
	int		i;

	count_range.min = 0;
	max_height = 0;
	i = 0;
	while (i <= index)
	{
		if (*column->height_ptr[i] > max_height)
		{
			max_height = *column->height_ptr[i];
			count_range.min++;
		}
		i++;
	}
	i = column->n - max_height;
	count_range.max = count_range.min + i;
	if (i)
		count_range.min++;
	return (count_range);
}

int	get_count_right(int *column, int n)
{
	int	i;
	int	max_height;
	int	count;

	count = 0;
	i = n;
	while (i--)
	{
		if (column[i] > max_height)
		{
			max_height = column[i];
			count++;
		}
	}
	return (count);
}

t_range	get_count_range_right(int index, const t_column *column)
{
	t_range	count_range;
	int		max_height;
	int		heightmap;
	int		i;

	count_range.min = 0;
	heightmap = (1 << column->n) - 1;
	max_height = 1 << (column->n - 1);
	i = 0;
	while (i <= index)
	{
		heightmap ^= (1 << (*column->height_ptr[i] - 1));
		if (!(heightmap & max_height))
			count_range.min++;
		while (heightmap && !(heightmap & max_height))
			max_height >>= 1;
		i++;
	}
	count_range.max = count_range.min;
	if (heightmap)
		count_range.min++;
	count_range.max += count_1s(heightmap);
	return (count_range);
}
