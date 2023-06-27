/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:32:32 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/27 14:26:41 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//Take the content
//and create an empty matrix for problem solving

// The function creates a convinient matrix for solving
// we replace obstacle char with 0 and empty with 1 (ints)
// This will allow us treat the problem as finding biggest sqr
int	**prepare_matrix(char *content,
		int n_lines, int len_of_line, t_marker markers)
{
	int		**matrix;
	int		i;
	int		j;

	matrix = (int **) malloc(n_lines * sizeof(int *));
	i = 0;
	while (i < n_lines)
	{
		matrix[i] = (int *) malloc(len_of_line * sizeof(int));
		j = 0;
		while (j < len_of_line)
		{
			matrix[i][j] = (*content == markers.empty);
			j++;
			content++;
		}
		content++;
		i++;
	}
	return (matrix);
}
