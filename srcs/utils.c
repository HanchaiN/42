/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:36:47 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/26 11:36:48 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "useful_funcs.h"

//Prints the given string to std output
void	ft_putstr(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0' )
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
}

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	str_to_num(char *str)
{
	int	result;

	result = 0;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

int	len_line(char *content)
{
	int	len;

	len = 0;
	while (*content != '\n')
	{
		content++;
	}
	content++;
	while (*content != '\0' && *content != '\n')
	{
		len++;
		content++;
	}
	return (len);
}
