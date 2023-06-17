/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:57:45 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/17 15:30:36 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char	*str)
{
	char	*dest;
	int		i;

	dest = (char *) malloc((ft_strlen(str) + 1) * sizeof(char));
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*tab;
	int					i;

	tab = (t_stock_str *) malloc((ac + 1) * sizeof(t_stock_str));
	if (tab == NULL)
		return (tab);
	i = 0;
	while (i < ac)
	{
		tab[i] = (t_stock_str){
			.size = ft_strlen(av[i]),
			.str = av[i],
			.copy = ft_strdup(av[i])
		};
		i++;
	}
	tab[i] = (t_stock_str){.size = 0, .str = NULL, .copy = NULL};
	return (tab);
}
