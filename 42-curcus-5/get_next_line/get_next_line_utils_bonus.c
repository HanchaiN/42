/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:42:10 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/28 01:08:45 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t				i;
	unsigned const char	*s_;
	unsigned char		c_;

	s_ = (unsigned const char *)s;
	c_ = (unsigned char)c;
	i = 0;
	while (s_ && s_[i] != '\0')
	{
		if (s_[i] == c_)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

void	*ft_realloc_inc(void *ptr, size_t n, size_t cpy_n)
{
	void	*temp;

	temp = malloc(n);
	if (ptr)
		ft_memmove(temp, ptr, cpy_n);
	free(ptr);
	return (temp);
}
