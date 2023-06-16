/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_backtracker.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:34:52 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/16 16:02:10 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int	_next_state(const t_input *constraint, t_state *state)
{
	state -> j++;
	if (state -> j < constraint -> n)
		return (1);
	state -> j = 0;
	state -> i++;
	if (state -> i < constraint -> n)
		return (1);
	return (0);
}

int	_prev_state(const t_input *constraint, t_state *state)
{
	state -> j--;
	if (state -> j > 0)
		return (1);
	state -> j = constraint -> n - 1;
	state -> i--;
	if (state -> i > 0)
		return (1);
	return (0);
}

int	_backtrack(const t_input *constraint, t_state *state)
{
	int	height;

	height = 1;
	while (height <= constraint -> n)
	{
		state -> height[state -> i][state -> j] = height;
		if (is_valid(constraint, state))
		{
			if (!_next_state(constraint, state))
				return (1);
			if (_backtrack(constraint, state))
				return (1);
			_prev_state(constraint, state);
		}
		height++;
	}
	return (0);
}

int	**find_solution(t_input *constraint)
{
	t_state	state;

	state.height = malloc2d(constraint -> n, constraint -> n);
	state.i = 0;
	state.j = 0;
	if (_backtrack(constraint, &state))
		return (state.height);
	return (NULL);
}