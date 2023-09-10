/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:44:15 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/26 18:27:27 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*first;
	const char	*last;

	first = s1;
	while (*first != '\0' && ft_strchr(set, *first))
		first++;
	last = s1 + ft_strlen(s1);
	while (last >= first && ft_strchr(set, *last))
		last--;
	return (ft_substr(s1, first - s1, last - first + 1));
}
