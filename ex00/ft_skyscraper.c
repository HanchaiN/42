/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:54:31 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/17 10:20:09 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int	main(int argc, char **argv)
{
	t_constraint	*constraint;
	t_state			*solution;

	if (argc != 2)
		return (print_error(0));
	constraint = (t_constraint *) malloc(sizeof(t_constraint));
	parse_constraint(constraint, argv[1]);
	if (constraint->n <= 0)
	{
		free_constraint(constraint);
		return (print_error(0));
	}
	solution = find_solution(constraint);
	if (solution->i == constraint->n)
		print_board(constraint->n, solution->height);
	else
		print_error(0);
	free_state(solution, constraint);
	free_constraint(constraint);
	return (0);
}
