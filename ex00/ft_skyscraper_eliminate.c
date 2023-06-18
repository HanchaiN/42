/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_eliminate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:40:22 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/18 14:46:43 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

void	filter(t_column *col, int i, int value)
{
	(void) col;
	(void) i;
	(void) value;
	return ;
}

void	cross_check(t_column *cols, t_column *rows)
{
	(void) cols;
	(void) rows;
	return ;
}

void	set_perm(t_column *col, int i, t_column *rows)
{
	int	*perm;
	int	j;

	perm = get_perm(col->n, col->possible[0]);
	free(col->possible);
	col->possible_size = -1;
	j = 0;
	while (j < col->n)
	{
		*col->height_ptr[j] = perm[j];
		filter(&rows[j], i, *col->height_ptr[j]);
		j++;
	}
	return ;
}

int	eliminate_at(t_state *state, int i, int j)
{
	if (state->height[i][j] != 0)
		return (0);
	if (state->col[j].possible_size == 0)
		return (-1);
	if (state->col[j].possible_size == 1)
	{
		set_perm(&state->col[j], j, state->rows);
		cross_check(state->col, state->rows);
		cross_check(state->rows, state->col);
		return (1);
	}
	if (state->rows[i].possible_size == 0)
		return (-1);
	if (state->rows[i].possible_size == 1)
	{
		set_perm(&state->rows[i], i, state->col);
		cross_check(state->rows, state->col);
		cross_check(state->col, state->rows);
		return (1);
	}
	return (0);
}

int	eliminate(t_state *state, int n)
{
	int	i;
	int	j;
	int	status;
	int	changed;

	changed = 0;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			status = eliminate_at(state, i, j);
			if (status == 1)
				changed = 1;
			if (status == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (changed);
}
