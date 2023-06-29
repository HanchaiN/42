/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:44:03 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/11 08:56:26 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*dst;
	unsigned int	count;

	dst = dest;
	count = 0;
	while (*src != '\0' && count++ < n)
		*(dst++) = *(src++);
	while (count++ < n)
		*(dst++) = '\0';
	return (dest);
}
