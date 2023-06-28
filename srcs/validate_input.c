/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:05:09 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/27 15:05:22 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// Check that matrix contains only empty char 
// and obstacle char
// *matr - pointer to begining of matrix
int	check_matrix_chars(char *matr, t_marker markers)
{
	while (*matr != '\0')
	{
		if (*matr == '\n')
			matr++;
		else if (*matr != markers.empty && *matr != markers.obstacle)
			return (0);
		else
			matr++;
	}
	return (1);
}

// Check the matrix matches the shape we got
// *matr - pointer to begining of matrix
int	check_shape(char *matr, int m, int n)
{
	int	count_lines;
	int	count_chars;

	count_chars = 0;
	count_lines = 0;
	while (*matr != '\0')
	{
		if (*matr == '\n')
		{
			count_lines++;
			if (count_chars != n)
				return (0);
			count_chars = 0;
			matr++;
		}
		else
		{
			count_chars++;
			matr++;
		}
	}
	return (count_lines == m);
}

// Check structure marker for duplicatingc chars
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
