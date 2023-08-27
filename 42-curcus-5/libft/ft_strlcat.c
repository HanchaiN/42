/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:44:02 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/22 19:23:07 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = ft_strlen(dst);
	if (count >= size)
		return (size + ft_strlen(src));
	return (count + ft_strlcpy(dst + count, src, size - count));
}
