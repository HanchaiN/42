/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:19:13 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/12 08:55:40 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;

	count = 0;
	while (*src != '\0')
	{
		if (count < size - 1)
		{
			*dest = *src;
		}
		count++;
		src++;
		dest++;
	}
	if (size > 0)
		*dest = '\0';
	return (count);
}
