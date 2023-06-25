#include "ft_dict.h"
#include <string.h>

char	*ft_get_value(unsigned int key, char *path)
{
	(void) path;
	char *str = malloc(sizeof(char) * 512);
	switch (key)
	{
		case 0:
			strcpy(str, "zero");
			break;
		case 1:
			strcpy(str, "ichi");
			break;
		case 2:
			strcpy(str, "ni");
			break;
		case 3:
			strcpy(str, "san");
			break;
		case 4:
			strcpy(str, "yon");
			break;
		case 5:
			strcpy(str, "go");
			break;
		case 6:
			strcpy(str, "roku");
			break;
		case 7:
			strcpy(str, "nana");
			break;
		case 8:
			strcpy(str, "hachi");
			break;
		case 9:
			strcpy(str, "kyuu");
			break;
		case 10:
			strcpy(str, "juu");
			break;
		case 100:
			strcpy(str, "hyaku");
			break;
		case 1000:
			strcpy(str, "sen");
			break;
		case 10000:
			strcpy(str, "man");
			break;
		case 100000000:
			strcpy(str, "oku");
			break;
		default:
			free(str);
			str = NULL;
	}
	return (str);
}
