/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:42:10 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/27 15:54:37 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src)
		return (dest);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + n - i - 1)
				= *(unsigned char *)(src + n - i - 1);
			i++;
		}
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	void	*ptr;

	ptr = s;
	while ((size_t)(ptr - s) < n)
	{
		*(unsigned char *)ptr = 0;
		ptr++;
	}
}

char	*get_empty_string(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(char));
	if (str)
		*str = '\0';
	return (str);
}
