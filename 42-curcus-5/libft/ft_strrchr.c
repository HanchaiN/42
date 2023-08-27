/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:44:13 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/22 18:46:05 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (1)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			j = i;
		if (*(unsigned char *)(s + i) == '\0')
			break ;
		i++;
	}
	if (*(unsigned char *)(s + j) == (unsigned char)c)
		return ((char *)(s + j));
	return (NULL);
}
