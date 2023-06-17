/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_validator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:33:28 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/17 17:58:33 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

t_range	_get_count_range_left(int index, const t_column *column)
{
	t_range	count_range;
	int		max_height;
	int		i;

	count_range.min = 0;
	max_height = 0;
	i = 0;
	while (i <= index)
	{
		if (*column->height[i] > max_height)
		{
			max_height = *column->height[i];
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

t_range	_get_count_range_right(int index, const t_column *column)
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
		heightmap ^= (1 << (*column->height[i] - 1));
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

int	_is_valid_column(int index, const t_column *column)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (*column->height[i] == *column->height[index])
			return (0);
		i++;
	}
	if (!is_in_range(column->l_count, _get_count_range_left(index, column)))
		return (0);
	if (!is_in_range(column->r_count, _get_count_range_right(index, column)))
		return (0);
	return (1);
}

int	is_valid(t_state *state)
{
	if (!_is_valid_column(state->j, &state->col[state->i]))
		return (0);
	if (!_is_valid_column(state->i, &state->row[state->j]))
		return (0);
	return (1);
}
