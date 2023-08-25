/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_free_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:32:32 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/28 12:59:16 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

/** Deallocate the memory allocated for the grid and it's properties.
*/
void	bsq_free_grid(t_grid *grid)
{
	unsigned int	i;

	if (grid == NULL)
		return ;
	i = 0;
	while (i < grid->m)
	{
		free(grid->value[i]);
		i++;
	}
	free(grid->value);
	free(grid);
}
