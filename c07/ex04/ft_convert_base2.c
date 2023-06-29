/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:14:54 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/28 09:06:10 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_strlen(char *str)
{
	int		count;
	char	*ptr;

	count = 0;
	while (*str != '\0')
	{
		if (_findch(str + 1, *str) >= 0)
			return (-1);
		if (*str == '+' || *str == '-' || *str <= ' ' || *str > '~')
			return (-1);
		str++;
		count++;
	}
	if (count < 2)
		return (-1);
	return (count);
}

int	_findch(char *str, char ch)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == ch)
			return (index);
		index++;
	}
	return (-1);
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

char	*_is_negative(char *str, int *is_negative)
{
	while (is_whitespace(*str))
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

int	ft_atoi_base(char *str, char *base, int *nbr)
{
	int	digit;
	int	radix;
	int	is_negative;

	radix = _strlen(base);
	if (radix < 0)
		return (0);
	str = _is_negative(str, &is_negative);
	*nbr = 0;
	digit = _findch(base, *str);
	while (0 <= digit)
	{
		*nbr *= radix;
		if (is_negative)
			*nbr -= digit;
		else
			*nbr += digit;
		str++;
		digit = _findch(base, *str);
	}
	return (1);
}
