/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:47:49 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/22 11:07:46 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <unistd.h>

int	_main(int argc, char **argv, int byte_count, char *program_name)
{
	int	ret;
	int	i;

	if (argc == 0)
		return (ft_tail_stdin(byte_count, program_name));
	if (argc == 1)
		return (ft_tail_file(argv[0], byte_count, 0, program_name));
	ret = 0;
	i = 0;
	while (i < argc)
	{
		if (ft_tail_file(argv[i++], byte_count, 1, program_name))
		{
			if (i != argc)
				ft_putstr("\n", STDERR_FILENO);
			ret = 1;
		}
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	int	i;
	int	byte_count;

	if (argc < 2)
		return (1);
	if (argv[1][0] != '-' || argv[1][1] != 'c')
		return (1);
	if (argv[1][2] == '\0')
	{
		i = 3;
		byte_count = ft_atoi(argv[2], argv[0]);
	}
	else
	{
		i = 2;
		byte_count = ft_atoi(argv[1] + 2, argv[0]);
	}
	if (byte_count < 0)
		return (1);
	return (_main(argc - i, argv + i, byte_count, argv[0]));
}
