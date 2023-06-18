#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	check_error(char *inp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (inp[i])
	{
		if ((inp[i] >= '0' && inp[i] <= '9') && i % 2 == 0)
		{
			i++;
			j++;
		}
		else if (inp[i] == ' ' && i % 2 == 1)
			i++;
		else
			return (-1);
	}
	if (j % 4 != 0 || j == 0)
	{
		return (-2);
	}
	j /= 4;
	return (j);
}

int	get(int ***a, char *inp)
{
	int	i;
	int	j;
	int	c;

	j = check_error(inp);
	if (j < 0)
		return (j);
	i = 0;
	*a = (int **)malloc(4 * sizeof (int *));
	while (i < 4)
	{
		c = 0;
		(*a)[i] = (int *)malloc(j * sizeof (int));
		while (c < j)
		{
			if (*inp >= '0' && *inp <= '9')
			{
				(*a)[i][c] = *inp - '0';
				c++;
			}
			inp++;
		}
		i++;
	}
	return (j);
}

int	print_error(int code)
{
	write(1, "Error\n", 6);
	return (code);
}

int	main(int argc, char **argv)
{
	int	**a;
	int	n;

	if (argc != 2)
		return (print_error(0));
	a = NULL;
	n = get(&a, argv[1]);
	if (n < 0)
	{
		return (print_error(n));
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return (0);
}
