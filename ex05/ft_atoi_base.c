/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:14:54 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/11 15:34:41 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*_is_negative(char *str, int *is_negative)
{
	while (*str == ' ')
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

int	ft_atoi_base(char *str, char *base)
{
	int	val;
	int	digit;
	int	radix;
	int	is_negative;

	radix = _strlen(base);
	if (radix < 0)
		return (0);
	str = _is_negative(str, &is_negative);
	val = 0;
	digit = _findch(base, *str);
	while (0 <= digit)
	{
		val *= radix;
		if (is_negative)
			val -= digit;
		else
			val += digit;
		str++;
		digit = _findch(base, *str);
	}
	return (val);
}
