/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:36:47 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/28 08:58:48 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	count;

	count = 0;
	while (*dest != '\0')
	{
		dest++;
		count++;
	}
	if (count > size)
		count = size;
	while (*src != '\0')
	{
		if (count + 1 < size)
		{
			*dest = *src;
			dest++;
			*dest = '\0';
		}
		src++;
		count++;
	}
	return (count);
}
