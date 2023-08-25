/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:48:57 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/10 15:49:17 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include<stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
	return ;
}

/*
int	main(void)
{
	int	a = 42;
	int	b = 10;
	int div;
	int mod;

	ft_div_mod(a, b, &div, &mod);
	printf("%d / %d = %d r %d\n", a, b, div, mod);
	return 0;
}
*/
