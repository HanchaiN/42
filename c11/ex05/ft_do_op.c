/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:37:17 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/20 16:16:12 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

int	operate(int value1, int value2, char *operateur, int *ret)
{
	char	*operateur_tab[5];
	int		(*operator_tab[5])(int, int, int *);
	int		i;

	operateur_tab[0] = "+";
	operator_tab[0] = ft_add;
	operateur_tab[1] = "-";
	operator_tab[1] = ft_sub;
	operateur_tab[2] = "/";
	operator_tab[2] = ft_div;
	operateur_tab[3] = "*";
	operator_tab[3] = ft_mul;
	operateur_tab[4] = "%";
	operator_tab[4] = ft_mod;
	i = 0;
	while (i < 5)
	{
		if (ft_strcmp(operateur_tab[i], operateur) == 0)
			return (operator_tab[i](value1, value2, ret));
		i++;
	}
	*ret = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	int	ret;

	if (argc == 4
		&& operate(ft_atoi(argv[1]), ft_atoi(argv[3]), argv[2], &ret))
	{
		ft_putnbr(ret);
		ft_putchar('\n');
	}
	return (0);
}
