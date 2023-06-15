/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:08:07 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/14 12:37:00 by hnonpras         ###   ########.fr       */
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

char	*ft_stpcpy(char *dst, char *src)
{
	while (*src != '\0')
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return (dst);
}

unsigned long long	_strjoin_len(int size, char **strs, char *sep)
{
	int					i;
	unsigned long long	len;

	len = 1 + (size - 1) * ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char				*str;
	char				*ptr;
	int					i;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(char));
		*str = '\0';
		return (str);
	}
	str = (char *)malloc(_strjoin_len(size, strs, sep) * sizeof(char));
	ptr = ft_stpcpy(str, strs[0]);
	i = 1;
	while (i < size)
	{
		ptr = ft_stpcpy(ptr, sep);
		ptr = ft_stpcpy(ptr, strs[i]);
		i++;
	}
	return (str);
}

/*
#include<stdio.h>
int main()
{
	char *strs[] = {"Hello", "World", "!"};
	char sep[] = "";
	int size = 3;
	printf("%s\n", ft_strjoin(size, strs, sep));
	return (0);
}
*/
