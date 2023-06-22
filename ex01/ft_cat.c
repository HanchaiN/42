/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:47:49 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/22 10:54:41 by hnonpras         ###   ########.fr       */
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
	char	buffer[32767];

	read_count = read(fileno, buffer, 32767);
	while (read_count > 0)
	{
		write(STDOUT_FILENO, buffer, read_count);
		read_count = read(fileno, buffer, 32767);
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

void	ft_display_error(char *program_name, char *pathname, int status)
{
	if (!status)
		return ;
	ft_putstr(program_name, STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(basename(pathname), STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(strerror(status), STDERR_FILENO);
	ft_putstr("\n", STDERR_FILENO);
}

int	main(int argc, char **argv)
{
	int	i;
	int	status;
	int	ret;

	if (argc == 1)
		return (ft_display(STDIN_FILENO));
	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			status = ft_display(STDIN_FILENO);
		else
			status = ft_display_file(argv[i]);
		ft_display_error(argv[0], argv[i], status);
		if (status)
			ret = 1;
		i++;
	}
	return (ret);
}
