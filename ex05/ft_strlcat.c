/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:36:47 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/11 13:36:49 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*dest_;
	unsigned int	i;

	dest_ = dest;
	i = 0;
	while (*dest != '\0' && i < size)
	{
		dest++;
		i++;
	}
	while (*src != '\0' && i < size)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	*dest = '\0';
	return (i);
}
