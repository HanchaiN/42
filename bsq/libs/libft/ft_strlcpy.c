/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:19:13 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/28 08:58:53 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	count;

	count = 0;
	while (*src != '\0')
	{
		if (count + 1 < size)
		{
			*dest = *src;
			dest++;
		}
		count++;
		src++;
	}
	if (size > 0)
		*dest = '\0';
	return (count);
}
