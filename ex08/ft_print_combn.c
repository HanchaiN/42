/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:11:58 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/08 13:19:39 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

typedef struct s_state
{
	int		n;
	char	lower;
	int		is_first;
}	t_state;

void	_print_combn(t_state s_state, char *sep, int sep_size)
{
	char	digit;
	t_state	s_state_;

	if (s_state.n == 0)
	{
		if (s_state.is_first == 0)
			write(STDOUT_FILENO, sep, sep_size);
		return ;
	}
	s_state_ = s_state;
	s_state_.n--;
	digit = s_state.lower;
	while (digit <= '9')
	{
		sep[sep_size] = digit;
		s_state_.lower = digit + 1;
		if (s_state.is_first == 1 && digit == s_state.lower)
			write(STDOUT_FILENO, &digit, 1);
		_print_combn(s_state_, sep, sep_size + 1);
		s_state_.is_first = 0;
		digit++;
	}
	return ;
}

void	ft_print_combn(int n)
{
	char	sep[10];
	t_state	s_state;

	sep[0] = ',';
	sep[1] = ' ';
	s_state.n = n;
	s_state.lower = '0';
	s_state.is_first = 1;
	_print_combn(s_state, sep, 2);
	return ;
}
