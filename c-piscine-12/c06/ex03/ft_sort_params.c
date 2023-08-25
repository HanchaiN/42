/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:00:05 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/13 13:00:41 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
	return ;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 < *s2)
			return (-1);
		if (*s1 > *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*temp;
	int		i;
	int		j;
	int		k;

	i = 1;
	while (i < argc)
	{
		k = i;
		j = i;
		while (j < argc)
		{
			if (ft_strcmp(argv[j], argv[k]) < 0)
				k = j;
			j++;
		}
		temp = argv[i];
		argv[i] = argv[k];
		argv[k] = temp;
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
