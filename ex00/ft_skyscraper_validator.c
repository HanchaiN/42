/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_validator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:33:28 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/17 09:43:42 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int	_is_in_range(int value, t_range range)
{
	return (range.min <= value && value <= range.max);
}

t_range	_get_count_range_left(int index, int n, int *height)
{
	t_range	count_range;
	int		max_height;
	int		i;

	count_range.min = 0;
	count_range.max = n - 1;
	max_height = 0;
	i = 0;
	while (i < index)
	{
		if (height[i] > max_height)
		{
			max_height = height[i];
			count_range.min++;
		}
		if (height[i] > height[index])
			count_range.max--;
		i++;
	}
	i = count_range.max;
	count_range.max += count_range.min;
	if (i)
		count_range.min++;
	return (count_range);
}

int	_is_valid_column(int index, t_column *column)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (*column->height[i] == *column->height[index])
			return (0);
		i++;
	}
	return (1);
}

//TODO: fix
int	is_valid(const t_constraint *constraint, t_state *state)
{
	if (!_is_valid_column(state->j, &state->col[state->i]))
		return (0);
	if (!_is_valid_column(state->i, &state->row[state->j]))
		return (0);
	return (1);
}
