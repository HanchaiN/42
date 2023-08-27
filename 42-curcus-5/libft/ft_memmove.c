/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:43:37 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/27 18:45:45 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned const char	*src_;
	unsigned char		*dst_;

	if (dest == src)
		return (dest);
	src_ = (unsigned const char *)src;
	dst_ = (unsigned char *)dest;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			dst_[i] = src_[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i--)
			dst_[i] = src_[i];
	}
	return (dest);
}
