/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:54:32 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 09:34:25 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_buffer.h"
#include "ft_dict.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_buffer		*buffer;
	int				error_flag;
	char			*str;
	char			*dict_path;
	unsigned int	nbr;
	int				read_count;

	error_flag = 0;
	str = NULL;
	dict_path = (char *)g_default_dict;
	if (argc == 1)
	{
		str = (char *) malloc(1024 * sizeof(char));
		read_count = read(STDIN_FILENO, str, 1024);
		if (str[read_count - 1] == '\n')
			str[read_count - 1] = '\0';
	}
	else if (argc == 2)
		str = ft_strdup(argv[1]);
	else if (argc == 3)
	{
		dict_path = argv[1];
		str = ft_strdup(argv[2]);
	}
	else
		error_flag = 1;
	nbr = ft_parse_number(str, &error_flag);
	free(str);
	if (error_flag)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	buffer = ft_buffer_new(0);
	if (ft_put_number(nbr, dict_path, buffer))
	{
		error_flag = 1;
		write(STDERR_FILENO, "Dict Error\n", 11);
	}
	else
	{
		ft_buffer_putchar('\n', buffer);
		ft_buffer_print(buffer);
	}
	ft_buffer_free(buffer);
	return (error_flag);
}
