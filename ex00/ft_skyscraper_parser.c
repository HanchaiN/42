/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:54:21 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/18 14:45:15 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_skyscraper.h"

const char	*_parse_int(const char *inp, const int size, int **tab)
{
	int	i;

	*tab = (int *)malloc(size * sizeof(int));
	if (*tab == NULL)
		return (inp);
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
	int	argc;
	int	i;

	argc = 0;
	i = 0;
	while (inp[i])
	{
		if ('1' <= inp[i] && inp[i] <= '9' && i % 2 == 0)
			argc++;
		else if (inp[i] != ' ' || i % 2 != 1)
			return (0);
		i++;
	}
	if (argc % 4 != 0 || argc == 0)
	{
		return (0);
	}
	return (argc / 4);
}

int	parse_constraint(t_constraint *constraint, const char *inp)
{
	if (constraint == NULL)
		return (0);
	constraint->n = _get_size(inp);
	if (constraint->n <= 0)
		return (0);
	inp = _parse_int(inp, constraint->n, &constraint->top);
	if (constraint->top == NULL)
		return (0);
	inp = _parse_int(inp, constraint->n, &constraint->bottom);
	if (constraint->bottom == NULL)
		return (0);
	inp = _parse_int(inp, constraint->n, &constraint->left);
	if (constraint->left == NULL)
		return (0);
	inp = _parse_int(inp, constraint->n, &constraint->right);
	if (constraint->right == NULL)
		return (0);
	return (1);
}
