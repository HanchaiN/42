/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:11:58 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/08 10:54:37 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void)
{
	char		value[3];
	const char	sep[2] = ", ";

	value[0] = '0';
	while (value[0] <= '9')
	{
		value[1] = value[0] + 1;
		while (value[1] <= '9')
		{
			value[2] = value[1] + 1;
			while (value[2] <= '9')
			{
				if (value[0] != '0'
					|| value[1] != '1'
					|| value[2] != '2')
					write(STDOUT_FILENO, &sep, 2);
				write(STDOUT_FILENO, &value, 3);
				value[2]++;
			}
			value[1]++;
		}
		value[0]++;
	}
	return ;
}
