/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_display_grid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:53:39 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/28 13:19:03 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"

/** Display the grid with or without the square.
 * @param grid the pointer to the grid data.
 * @param square the pointer to the coordinate of the square;
 * will not draw if is `NULL`.
*/
void	bsq_display_grid(const t_grid *grid, const t_square *square,
				const t_marker marker)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < grid->m)
	{
		j = 0;
		while (j < grid->n)
		{
			if (square
				&& square->x0 < j && j - 1 <= square->x1
				&& square->y0 < i && i - 1 <= square->y1)
				ft_putchar(marker.full);
			else if (grid->value[i][j])
				ft_putchar(marker.empty);
			else
				ft_putchar(marker.obstacle);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
