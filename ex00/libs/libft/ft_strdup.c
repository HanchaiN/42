/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:51:13 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/25 19:22:43 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dst;
	char	*dst_ptr;

	dst = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	dst_ptr = dst;
	while (*src)
	{
		*dst_ptr = *src;
		dst_ptr++;
		src++;
	}
	*dst_ptr = '\0';
	return (dst);
}
