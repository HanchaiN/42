/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:44:17 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/27 18:46:18 by hnonpras         ###   ########.fr       */
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
		dst = malloc(1 * sizeof(char));
		if (dst)
			dst[0] = '\0';
		return (dst);
	}
	size = ft_strlen(s + start);
	if (len < size)
		size = len;
	dst = malloc((size + 1) * sizeof(char));
	if (dst)
	{
		ft_memcpy(dst, s + start, size);
		dst[size] = '\0';
	}
	return (dst);
}
