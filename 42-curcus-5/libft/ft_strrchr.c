/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:44:13 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/27 18:46:16 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t				i;
	size_t				j;
	unsigned const char	*s_;
	unsigned char		c_;

	s_ = (unsigned const char *)s;
	c_ = (unsigned char)c;
	i = 0;
	j = 0;
	while (1)
	{
		if (s_[i] == c_)
			j = i;
		if (s_[i] == '\0')
			break ;
		i++;
	}
	if (s_[j] == c)
		return ((char *)(s + j));
	return (NULL);
}
