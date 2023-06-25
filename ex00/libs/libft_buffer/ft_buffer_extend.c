/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_extend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:54:20 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/24 11:43:11 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include <stdlib.h>

void	ft_buffer_extend(t_buffer *buffer)
{
	char	*str;

	str = buffer->begin;
	buffer->capacity *= 2;
	buffer->begin = (char *) malloc(buffer->capacity);
	buffer->curr = buffer->begin;
	ft_buffer_putstr(str, buffer);
	free(str);
}
