/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:46:33 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 14:52:18 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*curr;
	size_t	i;

	ptr = malloc(count * size);
	curr = ptr;
	i = 0;
	while (i < count * size)
	{
		curr[i] = 0;
		i++;
	}
	return (ptr);
}
