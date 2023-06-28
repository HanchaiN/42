/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:49:22 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/28 13:08:39 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"
#include "ft_fileio.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	_read_lines(char **str, int fileno, unsigned int n)
{
	unsigned int	i;
	int				len;
	char			*buffer;

	buffer = ft_read_line(fileno);
	len = ft_strlen(buffer);
	*str = (char *) malloc((n * len + 1) * sizeof(char));
	ft_strlcpy(*str, buffer, n * len + 1);
	i = 0;
	while (++i < n && len > -2)
	{
		free(buffer);
		buffer = ft_read_line(fileno);
		if (buffer == NULL)
			len = -2;
		if (ft_strlen(buffer) != len)
			len = -1;
		if (len > 0)
			ft_strlcat(*str, buffer, n * len + 1);
	}
	free(buffer);
	if (len < 0
		|| (fileno != STDIN_FILENO && ft_read_line(fileno) != NULL))
		return (-1);
	return (len - 1);
}

static int	_main_solve(t_marker marker, t_grid *grid)
{
	t_square	*square;

	square = bsq_find_largest_square(grid);
	bsq_display_grid(grid, square, marker);
	bsq_free_grid(grid);
	free(square);
	return (0);
}

static int	_main_parse(int fileno)
{
	char		*str;
	t_marker	marker;
	t_grid		*grid;
	int			m;
	int			n;

	if (fileno < 0)
		return (1);
	str = ft_read_line(fileno);
	m = bsq_parse_header(str, &marker);
	printf("empty = %c, obst = %c, full = %c\n", marker.empty, marker.obstacle, marker.full);
	free(str);
	if (m <= 0 || !check_duplicates(marker))
		return (1);
	n = _read_lines(&str, fileno, m);
	if (n <= 0 || !check_matrix_chars(str, marker))
	{
		free(str);
		return (1);
	}
	grid = bsq_parse_grid(str, m, n, marker);
	free(str);
	return (_main_solve(marker, grid));
}

int	main(int argc, char **argv)
{
	int	fileno;
	int	ret;

	if (argc == 1)
	{
		if (_main_parse(STDIN_FILENO) == 0)
			return (0);
		ft_putendl_fd("map error", STDERR_FILENO);
		return (1);
	}
	ret = 0;
	argv++;
	while (*argv)
	{
		fileno = open(*argv, O_RDONLY);
		if (_main_parse(fileno) != 0)
		{
			ret = 1;
			ft_putendl_fd("map error", STDERR_FILENO);
		}
		close(fileno);
		argv++;
	}
	return (ret);
}
