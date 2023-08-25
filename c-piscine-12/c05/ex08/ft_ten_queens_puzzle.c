/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:03:44 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/13 12:31:05 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	_is_reachable(int r1, int c1, int r2, int c2)
{
	return (
		r1 == r2
		|| c1 == c2
		|| r1 - c1 == r2 - c2
		|| r1 + c1 == r2 + c2
	);
}

int	_is_safe(int r, int c, int rows[10])
{
	int	c_;

	c_ = 0;
	while (c_ < c)
	{
		if (_is_reachable(r, c, rows[c_], c_))
			return (0);
		c_++;
	}
	return (1);
}

void	_print_rows(int rows[10])
{
	int	c;

	c = 0;
	while (c < 10)
	{
		write(STDOUT_FILENO, &"0123456789"[rows[c]], 1);
		c++;
	}
	write(STDOUT_FILENO, "\n", 1);
	return ;
}

int	_queens_puzzle(int c, int rows[10])
{
	int			r;
	int			count;

	if (c >= 10)
	{
		_print_rows(rows);
		return (1);
	}
	r = 0;
	count = 0;
	while (r < 10)
	{
		if (!_is_safe(r, c, rows))
		{
			r++;
			continue ;
		}
		rows[c] = r;
		count += _queens_puzzle(c + 1, rows);
		r++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	buff[10];

	return (_queens_puzzle(0, buff));
}
