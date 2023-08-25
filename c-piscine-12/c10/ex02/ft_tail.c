/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:47:49 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/29 11:44:13 by hnonpras         ###   ########.fr       */
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
	int	status;
	int	ret;
	int	i;
	int	j;

	if (argc == 0)
	{
		status = ft_tail_stdin(byte_count);
		ft_display_error_errno(program_name, "-", status);
		return (1);
	}
	ret = 0;
	i = 0;
	j = 0;
	while (i < argc)
	{
		status = ft_tail_file(argv[i], byte_count,
				argc != 1, j != 0);
		if (status == 0)
			j++;
		ret |= (status != 0);
		ft_display_error_errno(program_name, argv[i], status);
		i++;
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
