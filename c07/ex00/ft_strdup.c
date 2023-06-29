/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:51:13 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/14 12:20:24 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned long long	ft_strlen(char *str)
{
	unsigned long long	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	char	*dst_ptr;

	dst = (char *)malloc(ft_strlen(src) * sizeof(char));
	dst_ptr = dst;
	while (*src != '\0')
	{
		*dst_ptr = *src;
		dst_ptr++;
		src++;
	}
	*dst_ptr = '\0';
	return (dst);
}
