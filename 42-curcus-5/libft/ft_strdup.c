/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:43:55 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/27 18:41:51 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;

	dst = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dst)
		ft_memcpy(dst, s, ft_strlen(s) + 1);
	return (dst);
}
