#include "ft_dict.h"
#include <stdlib.h>

unsigned int	ft_parse_number(char string[], int *error_flag)
{
	unsigned int	input_number;
	int	i;

	if (string == NULL)
	{
		*error_flag = 1;
		return (0);
	}
	input_number = 0;
	i = 0;
	while (string[i] != '\0')
	{
		if ( '0' <= string[i] && string[i] <= '9')
	{		if ( input_number >= 429496730 || (input_number >= 429496729 && string[i] > '5'))
	{			*error_flag = 1;
				return (0);
	}
			else
			{
				input_number = input_number * 10 + (string[i] - 48);
				++i;
			}
	}
		else
		{
			*error_flag = 1;
			return (0);
		}
	}
	return (input_number);
}