/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:32:32 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/26 15:32:46 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "useful_funcs.h"

//Read first line and extract markers
// for empty, obstacle and full cell respectively
// MUST BE FREED AFTER USAGE
char	*get_markers(char *content)
{
	char	*markers;
	int		i;

	markers = (char *) malloc(sizeof(char) * 3);
	while (is_num(*content))
	{
		content++;
	}
	i = 0;
	while (*content != '\n' && i <= 2)
	{
		markers[i] = *content;
		i++;
		content++;
	}
	return (markers);
}

//Take the content
//and create an empty matrix for problem solving
int	**create_empty_matrix(char *content)
{
	int		n_lines;
	int		len_of_line;
	int		**matrix;
	int		i;
	int		j;

	n_lines = str_to_num(content);
	len_of_line = len_line(content);
	matrix = (int **) malloc(n_lines * sizeof(int *));
	i = 0;
	j = 0;
	while (i < n_lines)
	{
		matrix[i] = (int *) malloc(len_of_line * sizeof(int));
		while (j < len_of_line)
		{
			matrix[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (matrix);
}
