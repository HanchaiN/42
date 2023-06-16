/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:33:28 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/16 16:05:37 by hnonpras         ###   ########.fr       */
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
		if (column->height[i] == column->height[index])
			return (0);
		i++;
	}
	return (1);
}

//TODO: fix
int	is_valid(const t_input *constraint, t_state *state)
{
	t_column	column;

	column.n = constraint->n;
	column.l_count = constraint->left[state->i];
	column.r_count = constraint->right[state->i];
	column.height = state->height[state->i];
	if (!_is_valid_column(state->j, &column))
		return (0);
	column.l_count = constraint->top[state->j];
	column.r_count = constraint->bottom[state->j];
	column.height = get_row(state->height, constraint->n, state->j);
	if (!_is_valid_column(state->i, &column))
	{
		free(column.height);
		return (0);
	}
	free(column.height);
	return (1);
}