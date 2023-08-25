/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:59:08 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/08 10:54:48 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n)
{
	const char	positive_out = 'P';
	const char	negative_out = 'N';

	if (n < 0)
		write(STDOUT_FILENO, &negative_out, 1);
	else
		write(STDOUT_FILENO, &positive_out, 1);
	return ;
}
