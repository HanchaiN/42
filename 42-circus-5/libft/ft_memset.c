/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:43:40 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/22 18:43:40 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*ptr;

	ptr = s;
	while ((size_t)(ptr - s) < n)
	{
		*(unsigned char *)ptr = c;
		ptr++;
	}
	return (s);
}
