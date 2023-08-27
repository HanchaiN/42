/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:43:53 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/27 18:46:35 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t				i;
	unsigned const char	*s_;
	unsigned char		c_;

	s_ = (unsigned const char *)s;
	c_ = (unsigned char)c;
	i = 0;
	while (1)
	{
		if (s_[i] == c_)
			return ((char *)(s + i));
		if (s_[i] == '\0')
			return (NULL);
		i++;
	}
}
