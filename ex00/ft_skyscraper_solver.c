/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_solver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:34:52 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/18 12:30:38 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

t_state	*find_solution(const t_constraint *constraint)
{
	t_state	*state;

	if (constraint == NULL)
		return (NULL);
	state = (t_state *) malloc(sizeof(t_state));
	if (state == NULL || !init_state(state, constraint))
	{
		free_state(state, constraint);
		return (NULL);
	}
	freeze_state(state, constraint);
	if (!_backtrack(constraint, state))
	{
		free_state(state, constraint);
		return (NULL);
	}
	unfreeze_state(state, constraint);
	return (state);
}
