/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:43:59 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/27 10:53:26 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;

	dst = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dst)
		return (dst);
	ft_memcpy(dst, s1, ft_strlen(s1));
	ft_memcpy(dst + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (dst);
}
