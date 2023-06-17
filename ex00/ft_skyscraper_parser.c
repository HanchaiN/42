/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:54:21 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/17 09:44:47 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

const char	*_parse_int(const char *inp, const int size, int **tab)
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

int	_get_size(const char *inp)
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

void	parse_constraint(t_constraint *constraint, const char *inp)
{
	constraint->n = _get_size(inp);
	inp = _parse_int(inp, constraint->n, &constraint->top);
	inp = _parse_int(inp, constraint->n, &constraint->bottom);
	inp = _parse_int(inp, constraint->n, &constraint->left);
	inp = _parse_int(inp, constraint->n, &constraint->right);
}
