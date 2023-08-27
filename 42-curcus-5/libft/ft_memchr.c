/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:43:23 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/27 18:47:03 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*s_;
	unsigned char		c_;

	s_ = (unsigned const char *)s;
	c_ = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_[i] == c_)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
