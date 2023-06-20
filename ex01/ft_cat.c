/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:47:49 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/20 10:49:02 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <sys/errno.h>
#include <unistd.h>

void	ft_putstr(char *str, int fileno)
{
	while (*str)
		write(fileno, str++, 1);
}

int	ft_display(int fileno)
{
	int		read_count;
	char	buffer[16];

	read_count = read(fileno, buffer, 16);
	while (read_count > 0)
	{
		write(STDOUT_FILENO, buffer, read_count);
		read_count = read(fileno, buffer, 16);
	}
	if (read_count < 0)
		return (errno);
	return (0);
}

int	ft_display_file(char *pathname)
{
	int	fileno;
	int	status;

	fileno = open(pathname, O_RDONLY);
	if (fileno < 0)
		return (errno);
	status = ft_display(fileno);
	close(fileno);
	return (status);
}

int	ft_cat(int argc, char **argv)
{
	int	i;
	int	status;

	if (argc == 1)
		return (ft_display(STDIN_FILENO));
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			status = ft_display(STDIN_FILENO);
		else
			status = ft_display_file(argv[i]);
		if (status)
		{
			ft_putstr("ft_cat: ", STDERR_FILENO);
			ft_putstr(basename(argv[i]), STDERR_FILENO);
			ft_putstr(": ", STDERR_FILENO);
			return (status);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	status;

	status = ft_cat(argc, argv);
	if (status)
		ft_putstr(strerror(status), STDERR_FILENO);
	return (status);
}
