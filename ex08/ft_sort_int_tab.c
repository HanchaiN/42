/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:46:12 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/10 16:46:13 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	ind;
	int	min_ind;

	if (size == 0)
		return ;
	ind = 0;
	min_ind = 0;
	while (ind < size)
	{
		if (tab[ind] < tab[min_ind])
			min_ind = ind;
		ind++;
	}
	temp = tab[0];
	tab[0] = tab[min_ind];
	tab[min_ind] = temp;
	ft_sort_int_tab(tab + 1, size - 1);
	return ;
}

/*
int main(void)
{
	int tab[] = {9, 8, 7, 6, 5, 0, 1, 2, 3, 4};
	int len = sizeof(tab) / sizeof(tab[0]);
	for(int i = 0; i < len; i++)
		printf("%d ", tab[i]);
	printf("\n");
	ft_sort_int_tab(tab, len);
	for(int i = 0; i < len; i++)
		printf("%d ", tab[i]);
	printf("\n");
	return 0;
}
*/
