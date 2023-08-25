/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:56:49 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/10 15:56:53 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
	return ;
}

/*
int	main(void)
{
	int	a = 42;
	int	b = 10;

	printf("%d / %d = ", a, b);
	ft_ultimate_div_mod(&a, &b);
	printg("%d r %d\n", a, b);
	return 0;
}
*/
