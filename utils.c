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

#include "bsq_funcs.h"

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
