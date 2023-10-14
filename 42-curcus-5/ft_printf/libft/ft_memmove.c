/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:43:37 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/25 14:49:38 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + n - i - 1) = *(unsigned char *)(src + n - i
				- 1);
		i++;
	}
	return (dest);
}
