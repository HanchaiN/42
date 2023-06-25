/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:54:20 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/24 14:36:08 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include <stdlib.h>

t_buffer	*ft_buffer_new(unsigned int capacity)
{
	t_buffer	*buffer;

	if (capacity == 0)
		capacity = 1;
	buffer = (t_buffer *) malloc(sizeof(t_buffer));
	buffer->capacity = capacity;
	buffer->begin = (char *) malloc(buffer->capacity);
	buffer->curr = buffer->begin;
	*buffer->curr = 0;
	return (buffer);
}
