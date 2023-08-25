/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:11:58 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/08 11:30:11 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb2(void)
{
	int			value[2];
	char		string[3];
	const char	sep[2] = ", ";

	string[2] = ' ';
	value[0] = 0;
	while (value[0] <= 99)
	{
		value[1] = value[0] + 1;
		while (value[1] <= 99)
		{
			if (value[0] != 0 || value[1] != 1)
				write(STDOUT_FILENO, &sep, 2);
			string[0] = '0' + value[0] / 10;
			string[1] = '0' + value[0] % 10;
			write(STDOUT_FILENO, &string, 3);
			string[0] = '0' + value[1] / 10;
			string[1] = '0' + value[1] % 10;
			write(STDOUT_FILENO, &string, 2);
			value[1]++;
		}
		value[0]++;
	}
	return ;
}
