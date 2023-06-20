/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:36:47 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/15 15:28:58 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	count;

	count = 0;
	while (*dest != '\0')
	{
		dest++;
		count++;
	}
	if (count > size)
		count = size;
	while (*src != '\0')
	{
		if (count + 1 < size)
		{
			*dest = *src;
			dest++;
			*dest = '\0';
		}
		src++;
		count++;
	}
	return (count);
}
