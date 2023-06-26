#include "bsq.h"

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	str_to_num(char *str)
{
	int	result;

	result = 0;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

int	len_line(char *content)
{
	int	len;

	len = 0;
	while (*content != '\n')
	{
		content++;
	}
	content++;
	while (*content != '\0' && *content != '\n')
	{
		len++;
		content++;
	}
	return (len);
}
