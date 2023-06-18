/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:26:15 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/18 14:46:43 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int	_init_column(t_column *col, int n, int l_count, int r_count)
{
	col->n = n;
	col->l_count = l_count;
	col->r_count = r_count;
	col->height_ptr = (int **) malloc(n * sizeof(int *));
	if (col->height_ptr == NULL)
		return (0);
	if (!generate_possible_columns(col))
		return (0);
	return (1);
}

int	_link_columns(t_state *state, const t_constraint *constraint)
{
	int	i;
	int	j;

	i = 0;
	while (i < constraint->n)
	{
		if (!_init_column(&state->col[i], constraint->n,
				constraint->left[i], constraint->right[i]))
			return (0);
		j = 0;
		while (j < constraint->n)
		{
			if (i == 0 && !_init_column(&state->rows[j], constraint->n,
					constraint->top[j], constraint->bottom[j]))
				return (0);
			state->col[i].height_ptr[j] = &state->height[i][j];
			state->rows[j].height_ptr[i] = &state->height[i][j];
			j++;
		}
		i++;
	}
	return (1);
}

int	init_state(t_state *state, const t_constraint *constraint)
{
	state->n = constraint->n;
	state->i = 0;
	state->j = -1;
	state->height = malloc2d(state->n, state->n);
	state->col = (t_column *) malloc(state->n * sizeof(t_column));
	state->rows = (t_column *) malloc(state->n * sizeof(t_column));
	if (state->col == NULL || state->rows == NULL)
		return (0);
	if (!_link_columns(state, constraint))
		return (0);
	return (1);
}
