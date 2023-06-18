/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:54:31 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/18 14:45:31 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int	main(int argc, char **argv)
{
	t_constraint	*constraint;
	t_state			*solution;

	constraint = (t_constraint *) malloc(sizeof(t_constraint));
	solution = (t_state *) malloc(sizeof(t_state));
	if (argc == 2
		&& parse_constraint(constraint, argv[1])
		&& init_state(solution, constraint)
		&& find_solution(solution))
		print_board(constraint->n, solution->height);
	else
		print_error(0);
	free_state(solution);
	free_constraint(constraint);
	return (0);
}
