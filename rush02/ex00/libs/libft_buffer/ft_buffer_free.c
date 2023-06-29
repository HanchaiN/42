/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:54:20 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/24 11:43:16 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include <stdlib.h>

void	ft_buffer_free(t_buffer *buffer)
{
	free(buffer->begin);
	free(buffer);
}
