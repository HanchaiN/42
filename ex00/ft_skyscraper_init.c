/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:26:15 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/18 12:27:44 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int	init_column(t_column *col, int n, int l_count, int r_count)
{
	col->n = n;
	col->height = (int **) malloc(n * sizeof(int *));
	col->l_count = l_count;
	col->r_count = r_count;
	if (col->height == NULL)
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
		if (!init_column(&state->col[i], constraint->n,
				constraint->left[i], constraint->right[i]))
			return (0);
		j = 0;
		while (j < constraint->n)
		{
			if (i == 0 && !init_column(&state->row[j], constraint->n,
					constraint->top[j], constraint->bottom[j]))
				return (0);
			state->col[i].height[j] = &state->height[i][j];
			state->row[j].height[i] = &state->height[i][j];
			j++;
		}
		i++;
	}
	return (1);
}

int	init_state(t_state *state, const t_constraint *constraint)
{
	state->height = malloc2d(constraint->n, constraint->n);
	state->i = 0;
	state->j = 0;
	state->col = (t_column *) malloc(constraint->n * sizeof(t_column));
	state->row = (t_column *) malloc(constraint->n * sizeof(t_column));
	if (state->col == NULL || state->row == NULL)
		return (0);
	if (!_link_columns(state, constraint))
		return (0);
	return (1);
}

void	freeze_state(t_state *state, const t_constraint *constraint)
{
	int	i;
	int	j;

	i = 0;
	while (i < constraint->n)
	{
		j = 0;
		while (j < constraint->n)
		{
			if (state->height[i][j] > 0)
				state->height[i][j] *= -1;
			j++;
		}
		i++;
	}
}

void	unfreeze_state(t_state *state, const t_constraint *constraint)
{
	int	i;
	int	j;

	i = 0;
	while (i < constraint->n)
	{
		j = 0;
		while (j < constraint->n)
		{
			if (state->height[i][j] < 0)
				state->height[i][j] *= -1;
			j++;
		}
		i++;
	}
}
