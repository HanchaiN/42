/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:45:37 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/13 16:37:09 by hnonpras         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	if (argc <= 0)
		return (0);
	ft_putstr(argv[0]);
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
