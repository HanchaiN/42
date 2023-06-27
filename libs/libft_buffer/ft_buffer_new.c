/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:54:20 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/27 15:00:22 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include <stdlib.h>

/** Initialize buffer with certain capacity
 * @param capacity initial capacity of the buffer;
 * Automatically defaults to `1` if `0` is passed in
 * @return pointer to the buffer
*/
t_buffer	*ft_buffer_new(unsigned int capacity)
{
	t_buffer	*buffer;

	if (capacity == 0)
		capacity = 1;
	buffer = (t_buffer *)malloc(sizeof(t_buffer));
	buffer->capacity = capacity;
	buffer->begin = (char *)malloc(buffer->capacity);
	buffer->curr = buffer->begin;
	*buffer->curr = 0;
	return (buffer);
}
