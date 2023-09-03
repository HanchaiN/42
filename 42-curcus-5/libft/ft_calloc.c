/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:42:46 by hnonpras          #+#    #+#             */
/*   Updated: 2023/09/03 18:16:27 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	alloc_size;

	alloc_size = count * size;
	if (alloc_size != 0 && alloc_size / size != count)
		return (NULL);
	ptr = malloc(alloc_size);
	if (ptr)
		ft_bzero(ptr, alloc_size);
	return (ptr);
}
