/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_find_largest_square.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:54:46 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 12:42:24 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

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

static unsigned int	_min(unsigned int *tab, unsigned int count)
{
	unsigned int	i;
	unsigned int	val;

	val = tab[0];
	i = 1;
	while (i < count)
	{
		if (tab[i] < val)
			val = tab[i];
		i++;
	}
	return (val);
}

static void	*_calloc(unsigned int count, unsigned int size)
{
	void			*ptr;
	char			*curr;
	unsigned int	i;

	ptr = malloc(count * size);
	curr = ptr;
	i = 0;
	while (i < count * size)
	{
		curr[i] = 0;
		i++;
	}
	return (ptr);
}

t_square	*bsq_find_largest_square(int x, int y, int **grid)
{
	t_square	*solution;
	int			*max_size;
	int			i;
	int			j;

	solution = NULL;
	max_size = (int *) _calloc(2 * (x + 1), sizeof(int));
	i = 0;
	while (++i <= y)
	{
		j = 0;
		while (++j <= x)
		{
			if (!grid[i][j])
				max_size[(i % 2) * x + j] = 0;
			else
				max_size[(i % 2) * x + j] = 1 + _min((unsigned int [3]){
						max_size[(1 - i % 2) * x + j - 1],
						max_size[(i % 2) * x + j - 1],
						max_size[(1 - i % 2) * x + j]}, 3);
			_update_solution(i, j, max_size[(i % 2) * x + j], &solution);
		}
	}
	free(max_size);
	return (solution);
}
