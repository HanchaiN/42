/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:36:47 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/12 09:25:47 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	count;

	count = 0;
	while (*dest != '\0')
	{
		if (i < size - 1)
			dest++;
		count++;
	}
	while (*src != '\0')
	{
		if (count < size - 1)
		{
			*dest = *src;
			dest++;
		}
		src++;
		count++;
	}
	*dest = '\0';
	return (count);
}
