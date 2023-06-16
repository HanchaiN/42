/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:54:31 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/16 15:54:18 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

void	_main(t_input data)
{
	int	**board;

	board = find_solution(&data);
	if (board)
	{
		print_board(data.n, board);
		free(board);
	}
}

int	main(int argc, char **argv)
{
	t_input	data;

	if (argc != 2)
		return (print_error(0));
	data = parse_input(argv[1]);
	if (data.n <= 0)
	{
		free_input(data);
		return (print_error(0));
	}
	_main(data);
	free_input(data);
	return (0);
}
