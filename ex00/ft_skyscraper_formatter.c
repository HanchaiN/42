/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_formatter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:13:23 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/17 13:46:01 by ppruetti         ###   ########.fr       */
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

//Tryout print_board(int h, int **board)
void	str_write(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	str_write_char(char c)
{
	write(1, &c, 1);
}

void	print_board(int n, int **board)
{
	int	index;
	int	jndex;

	index = 0;
	while (index < n)
	{
		jndex = 0;
		while (jndex < n)
		{
			str_write_char((char)(board[index][jndex] + '0'));
			if (jndex != n - 1)
				str_write(" ");
			jndex++;
		}
		if (index != n - 1)
			str_write("\n");
		index++;
	}
}
