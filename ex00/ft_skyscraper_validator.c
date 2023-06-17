/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_validator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:33:28 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/17 11:54:07 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int	_is_in_range(const int value, const t_range range)
{
	return (range.min <= value && value <= range.max);
}

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

int	_get_count_right(const t_column *column)
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = column->n - 1;
	while (i >= 0)
	{
		if (*column->height[i] > max_height)
		{
			max_height = *column->height[i];
			count++;
		}
		i--;
	}
	return (count);
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
	if (!_is_in_range(column->l_count, _get_count_range_left(index, column)))
		return (0);
	if (index == column->n - 1 && _get_count_right(column) != column->r_count)
		return (0);
	return (1);
}

//TODO: fix
int	is_valid(t_state *state)
{
	if (!_is_valid_column(state->j, &state->col[state->i]))
		return (0);
	if (!_is_valid_column(state->i, &state->row[state->j]))
		return (0);
	return (1);
}
