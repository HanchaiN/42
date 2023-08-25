/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:29:23 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/10 16:46:27 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	l_ind;
	int	r_ind;

	l_ind = 0;
	r_ind = size - 1;
	while (l_ind < r_ind)
	{
		temp = tab[l_ind];
		tab[l_ind] = tab[r_ind];
		tab[r_ind] = temp;
		l_ind++;
		r_ind--;
	}
	return ;
}

/*
int main(void)
{
	int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int len = sizeof(tab) / sizeof(tab[0]);
	for(int i = 0; i < len; i++)
		printf("%d ", tab[i]);
	printf("\n");
	ft_rev_int_tab(tab, len);
	for(int i = 0; i < len; i++)
		printf("%d ", tab[i]);
	printf("\n");
	return 0;
}
*/
