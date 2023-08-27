/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:43:40 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/27 18:39:25 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_;
	unsigned char	c_;

	s_ = (unsigned char *)s;
	c_ = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		s_[i] = c_;
		i++;
	}
	return (s);
}
