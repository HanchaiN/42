/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:19:13 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/10 18:19:16 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*dst;
	unsigned int	count;

	dst = dest;
	count = 0;
	while (*src != '\0' && count < size - 1)
	{
		*(dst++) = *(src++);
		count++;
	}
	*dst = '\0';
	return (count);
}
