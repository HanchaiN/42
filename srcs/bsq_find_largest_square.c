/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_find_largest_square.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:54:46 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/28 12:50:49 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"
#include <stdlib.h>
#include <stdio.h>

static void	_update_solution(unsigned int x1, unsigned int y1,
			unsigned int size, t_square **solution)
{
	if (size == 0)
		return ;
	if (*solution == NULL)
	{
		*solution = (t_square *) malloc(sizeof(t_square));
		(*solution)->x0 = 0;
		(*solution)->x1 = 0;
		(*solution)->y0 = 0;
		(*solution)->y1 = 0;
	}
	else if ((*solution)->x1 - (*solution)->x0 + 1 >= size)
		return ;
	(*solution)->x0 = x1 - size + 1;
	(*solution)->y0 = y1 - size + 1;
	(*solution)->x1 = x1;
	(*solution)->y1 = y1;
}

static size_t	_get_index(size_t i, size_t j, size_t n)
{
	return ((i % 2) * (n + 1) + j);
}

/** Find the biggest square avoiding obstacles.
 * @return coordinate of the square malloc(3)ed by the call;
 * `NULL` if none exists.
*/
t_square	*bsq_find_largest_square(const t_grid *grid)
{
	t_square	*solution;
	int			*size;
	size_t		i;
	size_t		j;

	solution = NULL;
	size = (int *) ft_calloc(2 * (grid->n + 1), sizeof(int));
	i = 0;
	while (++i <= grid->m)
	{
		j = 0;
		while (++j <= grid->n)
		{
			if (!grid->value[i - 1][j - 1])
				size[_get_index(i, j, grid->n)] = 0;
			else
				size[_get_index(i, j, grid->n)] = 1 + ft_min((unsigned int [])
					{size[_get_index(i - 1, j - 1, grid->n)],
						size[_get_index(i, j - 1, grid->n)],
						size[_get_index(i - 1, j, grid->n)]}, 3);
			_update_solution(j, i, size[_get_index(i, j, grid->n)], &solution);
		}
	}
	free(size);
	return (solution);
}
