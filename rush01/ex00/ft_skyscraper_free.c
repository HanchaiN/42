/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:26:15 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/18 14:46:43 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

void	free_column(t_column *col)
{
	if (col == NULL)
		return ;
	if (col->height_ptr != NULL)
		free(col->height_ptr);
	if (col->possible != NULL)
		free(col->possible);
}

void	free_state(t_state *state)
{
	int	i;

	if (state == NULL)
		return ;
	i = 0;
	while (i < state->n)
	{
		if (state->col)
			free_column(&state->col[i]);
		if (state->rows)
			free_column(&state->rows[i]);
		i++;
	}
	if (state->col)
		free(state->col);
	if (state->rows)
		free(state->rows);
	free2d(state->height, state->n, state->n);
	free(state);
}

void	free_constraint(t_constraint *constraint)
{
	if (constraint == NULL)
		return ;
	if (constraint->top)
		free(constraint->top);
	if (constraint->bottom)
		free(constraint->bottom);
	if (constraint->left)
		free(constraint->left);
	if (constraint->right)
		free(constraint->right);
	free(constraint);
}
