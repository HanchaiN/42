/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:43:46 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/27 10:49:17 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(int n)
{
	if (n <= -10)
		return (get_length(-(n / 10)) + 2);
	else if (n < 0)
		return (2);
	else if (n >= 10)
		return (get_length(n / 10) + 1);
	else
		return (1);
}

static char	*putnbr_buffer(int n, char *buff)
{
	if (n <= -10)
	{
		*(buff++) = '-';
		buff = putnbr_buffer(-(n / 10), buff);
		buff = putnbr_buffer(-(n % 10), buff);
	}
	else if (n < 0)
	{
		*(buff++) = '-';
		buff = putnbr_buffer(-(n % 10), buff);
	}
	else if (n >= 10)
	{
		buff = putnbr_buffer(n / 10, buff);
		buff = putnbr_buffer(n % 10, buff);
	}
	else
	{
		*(buff++) = n + '0';
	}
	return (buff);
}

char	*ft_itoa(int n)
{
	char	*buff;

	buff = malloc((get_length(n) + 1) * sizeof(char));
	if (!buff)
		return (buff);
	*putnbr_buffer(n, buff) = '\0';
	return (buff);
}
