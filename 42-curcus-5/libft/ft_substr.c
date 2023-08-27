/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:44:17 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/25 16:01:06 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	size;

	if (start > ft_strlen(s))
	{
		dst = (char *)malloc(1 * sizeof(char));
		if (dst)
			dst[0] = '\0';
		return (dst);
	}
	size = ft_strlen(s + start);
	if (len < size)
		size = len;
	dst = (char *)malloc((size + 1) * sizeof(char));
	if (dst)
	{
		ft_memcpy(dst, s + start, size);
		dst[size] = '\0';
	}
	return (dst);
}
