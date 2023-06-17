/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_formatter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:13:23 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/17 13:24:53 by ppruetti         ###   ########.fr       */
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
void	print_board(int h, int **board)
{
	for(int i = 0; i < h; i++)
	{
		for(int j=0; j<h; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
}
