/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_malloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:26:15 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/17 10:03:55 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

void	init_column(t_column *col, int n, int l_count, int r_count)
{
	col->n = n;
	col->height = (int **) malloc(n * sizeof(int *));
	col->l_count = l_count;
	col->r_count = r_count;
}

void	free_column(t_column *col)
{
	free(col->height);
}

void	init_state(t_state *state, const t_constraint *constraint)
{
	int		i;
	int		j;

	state->height = malloc2d(constraint->n, constraint->n);
	state->i = 0;
	state->j = -1;
	state->col = (t_column *) malloc(constraint->n * sizeof(t_column));
	state->row = (t_column *) malloc(constraint->n * sizeof(t_column));
	i = 0;
	while (i < constraint->n)
	{
		init_column(&state->col[i], constraint->n,
			constraint->left[i], constraint->right[i]);
		j = 0;
		while (j < constraint->n)
		{
			if (i == 0)
				init_column(&state->row[j], constraint->n,
					constraint->top[j], constraint->bottom[j]);
			state->col[i].height[j] = &state->height[i][j];
			state->row[j].height[i] = &state->height[i][j];
			j++;
		}
		i++;
	}
}

void	free_state(t_state *state, const t_constraint *constraint)
{
	int	i;

	i = 0;
	while (i < constraint->n)
	{
		free_column(&state->col[i]);
		free_column(&state->row[i]);
		i++;
	}
	free(state->col);
	free(state->row);
	free2d(state->height, constraint->n, constraint->n);
	free(state);
}

void	free_constraint(t_constraint *data)
{
	free(data -> top);
	free(data -> bottom);
	free(data -> left);
	free(data -> right);
	free(data);
}
