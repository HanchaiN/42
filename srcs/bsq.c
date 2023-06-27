/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:49:22 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/27 16:12:31 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft_fileio.h"
#include <fcntl.h>
#include <unistd.h>

//Test part for test validation of matrix
/*
#include <stdio.h>
int	main()
{
	char		*content;
	t_marker	markers;

	content = ft_read_file("test.txt");
	markers = bsq_parse_header_markers(content);
	while (*content != '\n')
		content++;
	content++;
	printf("content char now = %c|", *content);
	printf("Check chars: %d\n", check_matrix_chars(content, markers));
	printf("Check shape: %d \n", check_shape(content, 5, 5));
}
*/



static int	_main(int fileno)
{
	char		*str;
	t_marker	marker;
	t_grid		grid;
	t_square	*square;

	if (fileno < 0)
		return (1);
	str = ft_read_line(fileno);
	grid.m = ft_atoi(str);
	marker = bsq_parse_header_markers(str);
	free(str);
	// TODO: Validate and parse the rest of the file.
	square = bsq_find_largest_square(&grid);
	bsq_display_grid(&grid, square, marker);
	return (0);
}


int	main(int argc, char **argv)
{
	int	fileno;
	int	ret;

	if (argc == 1)
		return (_main(STDIN_FILENO));
	ret = 0;
	argv++;
	while (*argv)
	{
		fileno = open(*argv, O_RDONLY);
		ret |= _main(fileno);
		close(fileno);
		argv++;
	}
	return (ret);
}
