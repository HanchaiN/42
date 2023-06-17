/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:26:15 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/17 17:25:23 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

void	free_column(t_column *col)
{
	if (col == NULL)
		return ;
	free(col->height);
}

void	free_state(t_state *state, const t_constraint *constraint)
{
	int	i;

	if (state == NULL)
		return ;
	i = 0;
	while (i < constraint->n)
	{
		if (state->col)
			free_column(&state->col[i]);
		if (state->row)
			free_column(&state->row[i]);
		i++;
	}
	if (state->col)
		free(state->col);
	if (state->row)
		free(state->row);
	free2d(state->height, constraint->n, constraint->n);
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
