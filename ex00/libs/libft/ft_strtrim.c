#include "ft.h"
#include <ctype.h>
#include <stdlib.h>

char	*ft_strtrim(char *src)
{
	char	*dst;
	char	*dst_ptr;

	dst = (char *)malloc(ft_strlen(src) * sizeof(char));
	dst_ptr = dst;
    while (ft_isspace(*src))
        src++;
	while (*src)
	{
        if(!ft_isspace(*src) || (*(src + 1) && !ft_isspace(*(src + 1))))
        {
            if (ft_isspace(*src))
                *dst_ptr = ' ';
            else
                *dst_ptr = *src;
            dst_ptr++;
        }
        src++;
	}
	*dst_ptr = '\0';
	return (dst);
}
