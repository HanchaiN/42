/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:47:49 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/22 09:58:20 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	ft_display_file(char *pathname)
{
	int		file_no;
	int		read_count;
	char	buffer[32767];

	file_no = open(pathname, O_RDONLY);
	if (file_no < 0)
		return (-1);
	read_count = read(file_no, buffer, 32767);
	while (read_count > 0)
	{
		write(STDOUT_FILENO, buffer, read_count);
		read_count = read(file_no, buffer, 32767);
	}
	close(file_no);
	if (read_count < 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		write(STDOUT_FILENO, "File name missing.\n", 19);
	else if (argc > 2)
		write(STDOUT_FILENO, "Too many arguments.\n", 20);
	else if (ft_display_file(argv[1]) != 0)
		write(STDOUT_FILENO, "Cannot read file.\n", 18);
	return (0);
}
