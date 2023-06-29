/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:54:32 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 22:21:27 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_buffer.h"
#include "ft_dict.h"
#include <stdlib.h>
#include <unistd.h>

void	_main(char *str, const char *dict_path, int *error_flag)
{
	t_buffer		*buffer;
	unsigned int	nbr;

	if (*error_flag)
		return ;
	nbr = ft_parse_number(str, error_flag);
	if (*error_flag)
		return ;
	buffer = ft_buffer_new(0);
	if (ft_put_number(nbr, dict_path, buffer))
		*error_flag |= 2;
	else
	{
		ft_buffer_putchar('\n', buffer);
		ft_buffer_print(buffer);
	}
	ft_buffer_free(buffer);
}

int	main(int argc, char **argv)
{
	int		error_flag;
	char	*str;
	char	*dict_path;

	error_flag = 0;
	str = NULL;
	dict_path = (char *) g_default_dict;
	if (argc == 3)
		dict_path = argv[1];
	if (argc == 1)
		str = ft_read_line(STDIN_FILENO);
	else if (argc == 2)
		str = ft_strdup(argv[1]);
	else if (argc == 3)
		str = ft_strdup(argv[2]);
	else
		error_flag |= 1;
	_main(str, dict_path, &error_flag);
	free(str);
	if (error_flag & 1)
		write(STDERR_FILENO, "Error\n", 6);
	if (error_flag & 2)
		write(STDERR_FILENO, "Dict Error\n", 11);
	return (error_flag);
}
