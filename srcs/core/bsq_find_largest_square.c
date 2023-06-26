/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_find_largest_square.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:54:46 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 14:59:53 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"
#include <stdlib.h>
#include <sys/types.h>

static void	_update_solution(unsigned int x1, unsigned int y1,
			unsigned int size, t_square **solution)
{
	if (size == 0)
		return ;
	if (*solution == NULL)
		*solution = (t_square *) malloc(sizeof(solution));
	if ((*solution)->x1 - (*solution)->x0 > size)
		return ;
	(*solution)->x0 = x1 - size;
	(*solution)->y0 = y1 - size;
	(*solution)->x1 = x1;
	(*solution)->y1 = y1;
}

t_square	*bsq_find_largest_square(size_t x, size_t y, const int **grid)
{
	t_square	*solution;
	int			*max_size;
	size_t		i;
	size_t		j;

	solution = NULL;
	max_size = (int *) ft_calloc(2 * (x + 1), sizeof(int));
	i = 0;
	while (++i <= y)
	{
		j = 0;
		while (++j <= x)
		{
			if (!grid[i][j])
				max_size[(i % 2) * x + j] = 0;
			else
				max_size[(i % 2) * x + j] = 1 + ft_min((unsigned int [3]){
						max_size[(1 - i % 2) * x + j - 1],
						max_size[(i % 2) * x + j - 1],
						max_size[(1 - i % 2) * x + j]}, 3);
			_update_solution(i, j, max_size[(i % 2) * x + j], &solution);
		}
	}
	free(max_size);
	return (solution);
}
