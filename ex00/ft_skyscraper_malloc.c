/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_cleanup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:26:15 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/16 15:47:36 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

void	free_input(t_input data)
{
	free(data.top);
	free(data.bottom);
	free(data.left);
	free(data.right);
}

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

int	*get_row(int **arr, int x, int j)
{
	int	*tab;
	int	i;

	tab = (int *) malloc(x * sizeof(int));
	i = 0;
	while (i < x)
	{
		tab[i] = arr[i][j];
		i++;
	}
	return (tab);
}

int	*rev_arr(int *arr, int size)
{
	int	*tab;
	int	i;

	tab = (int *) malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		tab[i] = arr[size - i - 1];
	}
	return (tab);
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