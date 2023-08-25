/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:44:15 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/25 14:43:35 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*first;
	const char	*last;
	char		*dst;

	first = s1;
	while (*first != '\0' && ft_strchr(set, *first))
		first++;
	last = s1 + ft_strlen(s1);
	while (last >= first && ft_strchr(set, *last))
		last--;
	dst = (char *)malloc((last - first + 2) * sizeof(char));
	if (dst)
	{
		ft_memcpy(dst, first, last - first + 1);
		dst[last - first + 1] = '\0';
	}
	return (dst);
}
