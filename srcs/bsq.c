/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:49:22 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/28 09:21:28 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft_fileio.h"
#include <fcntl.h>
#include <stdlib.h>
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

static int	_read_lines(char **str, int fileno, unsigned int m)
{
	unsigned int	i;
	int				n;
	char			*buffer;

	buffer = ft_read_line(fileno);
	n = ft_strlen(buffer);
	*str = (char *) malloc(m * n * sizeof(char));
	ft_strlcpy(*str, buffer, m * n);
	i = 0;
	while (i < m)
	{
		free(buffer);
		buffer = ft_read_line(fileno);
		if (buffer == NULL)
		{
			n = -1;
			break ;
		}
		if (ft_strlen(buffer) != n)
			n = -1;
		if (n > 0)
			ft_strlcpy(*str, buffer, m * n);
		i++;
	}
	free(buffer);
	if (n < 0
		|| (fileno != STDIN_FILENO && ft_read_line(fileno) != NULL))
	{
		free(*str);
		return (n);
	}
	return (n);
}

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
	grid.n = _read_lines(&str, fileno, grid.m);
	if (grid.n <= 0)
		return (1);
	// TODO: Validate everything.
	grid.value = prepare_matrix(str, grid.m, grid.n, marker);
	square = bsq_find_largest_square(&grid);
	bsq_display_grid(&grid, square, marker);
	return (0);
}


int	main(int argc, char **argv)
{
	int	fileno;
	int	ret;

	if (argc == 1)
	{
		if (_main(STDIN_FILENO))
		{
			ft_putendl_fd("map error", STDERR_FILENO);
			return (1);
		}
		else
		{
			return (0);
		}
	}
	ret = 0;
	argv++;
	while (*argv)
	{
		fileno = open(*argv, O_RDONLY);
		if (_main(fileno) != 0)
		{
			ret = 1;
			ft_putendl_fd("map error", STDERR_FILENO);
		}
		close(fileno);
		argv++;
	}
	return (ret);
}
