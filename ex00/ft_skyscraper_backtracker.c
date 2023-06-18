/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_backtracker.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:34:52 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/18 15:12:48 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int	_next_state(t_state *state)
{
	state->j++;
	if (state->j < state->n)
		return (1);
	state->j = 0;
	state->i++;
	if (state->i < state->n)
		return (1);
	return (0);
}

int	_prev_state(t_state *state)
{
	state->j--;
	if (state->j >= 0)
		return (1);
	state->j = state->n - 1;
	state->i--;
	if (state->i >= 0)
		return (1);
	return (0);
}

int	backtrack(t_state *state)
{
	int	height;

	if (!_next_state(state))
		return (1);
	if (state->height[state->i][state->j] != 0)
	{
		if (backtrack(state))
			return (1);
		else
		{
			_prev_state(state);
			return (0);
		}
	}
	height = 1;
	while (height <= state->n)
	{
		state->height[state->i][state->j] = height;
		if (is_valid(state) && backtrack(state))
			return (1);
		height++;
	}
	state->height[state->i][state->j] = 0;
	_prev_state(state);
	return (0);
}
