/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:54:20 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/27 15:00:48 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_buffer.h"

/** Print the content of the buffer to the standard outout
*/
void	ft_buffer_print(t_buffer *buffer)
{
	ft_putstr(buffer->begin);
}
