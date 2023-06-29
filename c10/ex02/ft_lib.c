/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:14:54 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/22 10:31:13 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include <unistd.h>

void	ft_putstr(char *str, int fileno)
{
	while (*str)
		write(fileno, str++, 1);
}

int	is_whitespace(char c)
{
	return (
		c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' '
	);
}

int	ft_atoi(char *str, char *program_name)
{
	char	*offset;
	int		val;

	offset = str;
	while (is_whitespace(*offset))
		offset++;
	val = 0;
	while (*offset)
	{
		if ('0' > *offset || *offset > '9')
		{
			ft_display_error_offset(program_name, str);
			return (-1);
		}
		val *= 10;
		val += *offset - '0';
		offset++;
	}
	return (val);
}
