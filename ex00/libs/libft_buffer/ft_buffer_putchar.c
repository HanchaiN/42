/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:54:20 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/24 11:34:40 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

void	ft_buffer_putchar(char ch, t_buffer *buffer)
{
	if (buffer->curr - buffer->begin >= buffer->capacity - 1)
		ft_buffer_extend(buffer);
	*buffer->curr = ch;
	buffer->curr++;
	*buffer->curr = 0;
}
