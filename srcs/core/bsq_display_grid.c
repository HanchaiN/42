/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_display_grid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:53:39 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/27 12:09:08 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"

void	bsq_display_grid(const t_grid *grid, const t_square *square,
				const t_marker marker)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < grid->y)
	{
		j = 0;
		while (j < grid->x)
		{
			if (square
				&& square->x0 <= j && j <= square->x1
				&& square->y0 <= i && i <= square->y1)
				ft_putchar(marker.full);
			else if (grid->value[i][j] == EMPTY)
				ft_putchar(marker.empty);
			else
				ft_putchar(marker.obstacle);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
