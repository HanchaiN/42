/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_formatter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:13:23 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/17 11:45:42 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int	print_error(int code)
{
	write(1, "Error\n", 6);
	printf("%d\n", code);
	fflush(stdout);
	return (code);
}

//TODO: implement w/o printf
void	print_board(int n, int **board)
{
	for(int i = 0; i < n; i++)
	{
		for(int j=0; j<n; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
}

void	print_column(const t_column *col)
{
	for(int i=0; i<col->n; i++)
		printf("%d ", *col->height[i]);
	printf("\n");
}