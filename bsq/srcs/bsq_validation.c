/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:05:09 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/28 13:11:13 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/** Check for undefined characters in the grid.
*/
int	check_matrix_chars(char *matr, t_marker markers)
{
	while (*matr != '\0')
	{
		if (*matr != markers.empty
			&& *matr != markers.obstacle
			&& *matr != '\n')
			return (0);
		else
			matr++;
	}
	return (1);
}

/** Check for identical marker characters.
*/
int	check_duplicates(t_marker marker)
{
	if (marker.empty == marker.obstacle)
		return (0);
	if (marker.empty == marker.full)
		return (0);
	if (marker.obstacle == marker.full)
		return (0);
	return (1);
}
