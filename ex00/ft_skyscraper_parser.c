/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:54:21 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/16 15:51:42 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

char	*_parse_int(char *inp, int size, int **tab)
{
	int	i;

	*tab = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		if (*tab && '0' <= *inp && *inp <= '9')
		{
			(*tab)[i] = *inp - '0';
			i++;
		}
		inp++;
	}
	return (inp);
}

int	_get_size(char *inp)
{
	int		argc;

	argc = 0;
	while (*inp)
	{
		if ('1' <= *inp && *inp <= '9')
			argc++;
		else if (*inp != ' ')
			return (0);
		inp++;
	}
	if (argc % 4 != 0 || argc == 0)
	{
		return (0);
	}
	return (argc / 4);
}

t_input	parse_input(char *inp)
{
	t_input	data;

	data.n = _get_size(inp);
	inp = _parse_int(inp, data.n, &data.top);
	inp = _parse_int(inp, data.n, &data.bottom);
	inp = _parse_int(inp, data.n, &data.left);
	inp = _parse_int(inp, data.n, &data.right);
	return (data);
}