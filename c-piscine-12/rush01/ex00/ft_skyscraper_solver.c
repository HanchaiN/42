/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_solver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:34:52 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/18 15:37:15 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int	find_solution(t_state *state)
{
	if (state == NULL)
		return (0);
	while (eliminate(state))
		continue ;
	return (backtrack(state));
}
