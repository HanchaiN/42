/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_parse_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:32:32 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/28 12:56:51 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

/** Parse multiple-line string into grid.
 * @param content the string.
 * @param n_lines number of lines
 * @param len_of_line number of characters per line (exclude newline).
 * @param markers look-up table for marker characters.
 * @return grid object with all properties.
*/
t_grid	*bsq_parse_grid(char *content,
		int n_lines, int len_of_line, t_marker markers)
{
	t_grid			*grid;
	unsigned int	i;
	unsigned int	j;

	grid = (t_grid *) malloc(sizeof(t_grid));
	grid->m = n_lines;
	grid->n = len_of_line;
	grid->value = (int **) malloc(grid->m * sizeof(int *));
	i = 0;
	while (i < grid->m)
	{
		grid->value[i] = (int *) malloc(grid->n * sizeof(int));
		j = 0;
		while (j < grid->n)
		{
			grid->value[i][j] = (*content == markers.empty);
			content++;
			j++;
		}
		content++;
		i++;
	}
	return (grid);
}
