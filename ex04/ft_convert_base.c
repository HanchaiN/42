/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:32:55 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/15 12:01:06 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	_strlen(char *str)
{
	int		count;
	char	*ptr;

	count = 0;
	while (*str != '\0')
	{
		ptr = str + 1;
		while (*ptr != '\0')
		{
			if (*ptr == *str)
				return (-1);
			ptr++;
		}
		if (*str == '+' || *str == '-' || *str <= ' ' || *str > '~')
			return (-1);
		str++;
		count++;
	}
	if (count < 2)
		return (-1);
	return (count);
}

char	*_is_negative(char *str, int *is_negative)
{
	while (
		*str == '\t'
		|| *str == '\n'
		|| *str == '\v'
		|| *str == '\f'
		|| *str == '\r'
		|| *str == ' '
	)
		str++;
	*is_negative = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*is_negative = !*is_negative;
		str++;
	}
	return (str);
}

int	_atoi_base(char *str, char *base, int *val)
{
	int	digit;
	int	radix;
	int	is_negative;

	radix = _strlen(base);
	if (radix < 0)
		return (-1);
	str = _is_negative(str, &is_negative);
	*val = 0;
	while (1)
	{
		digit = 0;
		while (base[digit] != *str || base[digit] == '\0')
		{
			if (base[digit] == '\0')
				return (is_negative);
			digit++;
		}
		*val *= radix;
		*val -= digit;
		str++;
	}
}

void	ft_rev_str(char *str, int len)
{
	char	temp;
	int		l_ind;
	int		r_ind;

	l_ind = 0;
	r_ind = len - 1;
	while (l_ind < r_ind)
	{
		temp = str[l_ind];
		str[l_ind] = str[r_ind];
		str[r_ind] = temp;
		l_ind++;
		r_ind--;
	}
	return ;
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		value;
	int		radix;
	int		i;
	int		is_negative;

	radix = _strlen(base_to);
	is_negative = _atoi_base(nbr, base_from, &value);
	if (radix < 0 || is_negative < 0)
		return (NULL);
	str = base_to;
	str = (char *)malloc(32 * sizeof(char));
	i = 0;
	while (value != 0 || i == 0)
	{
		str[i] = base_to[-(value % radix)];
		value /= radix;
		i++;
	}
	if (is_negative)
		str[i++] = '-';
	str[i] = '\0';
	ft_rev_str(str, i);
	return (str);
}
