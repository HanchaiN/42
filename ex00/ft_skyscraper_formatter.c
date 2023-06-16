/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_formatter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:13:23 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/16 16:04:16 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"
#include <stdio.h>

int	print_error(int code)
{
	write(1, "Error\n", 6);
	printf("%d\n", code);
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
