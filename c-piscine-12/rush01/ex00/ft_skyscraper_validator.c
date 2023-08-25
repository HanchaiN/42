/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_validator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:33:28 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/18 14:46:43 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int	_is_valid_column(int index, const t_column *column)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (*column->height_ptr[i] == *column->height_ptr[index])
			return (0);
		i++;
	}
	if (!is_in_range(column->l_count, get_count_range_left(index, column)))
		return (0);
	if (!is_in_range(column->r_count, get_count_range_right(index, column)))
		return (0);
	return (1);
}

int	is_valid(t_state *state)
{
	if (!_is_valid_column(state->j, &state->col[state->i]))
		return (0);
	if (!_is_valid_column(state->i, &state->rows[state->j]))
		return (0);
	return (1);
}
