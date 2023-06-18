/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:02:30 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/18 12:56:21 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

int	**malloc2d(int x, int y)
{
	int	**arr;
	int	i;
	int	j;

	arr = (int **) malloc(x * sizeof(int *));
	i = 0;
	while (i < x)
	{
		arr[i] = (int *) malloc(y * sizeof(int));
		j = 0;
		while (j < y)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (arr);
}

void	free2d(int **arr, int x, int y)
{
	int	i;

	(void)y;
	i = 0;
	while (i < x)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_in_range(const int value, const t_range range)
{
	return (range.min <= value && value <= range.max);
}

int	count_1s(int binary)
{
	int	count;

	count = 0;
	while (binary)
	{
		count += (binary & 1);
		binary >>= 1;
	}
	return (count);
}

int	factorial(int n)
{
	if (n <= 0)
		return (1);
	return (n * factorial(n - 1));
}
