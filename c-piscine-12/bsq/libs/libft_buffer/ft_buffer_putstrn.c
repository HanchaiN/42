/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_putstrn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:54:20 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/27 15:01:41 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

/** Append a string up to certain characters to the buffer
*/
void	ft_buffer_putstrn(char *str, int n, t_buffer *buffer)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
	{
		ft_buffer_putchar(str[i], buffer);
		i++;
	}
}
