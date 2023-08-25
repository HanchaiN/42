/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:54:20 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 09:28:09 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "ft_dict.h"
#include <stdlib.h>

int	ft_put_value(unsigned int key, const char *path, t_buffer *buffer)
{
	char	*str;

	str = ft_get_value(key, path);
	if (!str)
		return (1);
	ft_buffer_putstr(str, buffer);
	free(str);
	return (0);
}
