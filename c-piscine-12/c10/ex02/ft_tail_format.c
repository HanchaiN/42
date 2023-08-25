/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:14:54 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/29 10:09:37 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include <libgen.h>
#include <string.h>
#include <unistd.h>

void	ft_display_error_errno(char *program_name, char *pathname, int status)
{
	if (!status)
		return ;
	ft_putstr(basename(program_name), STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(basename(pathname), STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(strerror(status), STDERR_FILENO);
	ft_putstr("\n", STDERR_FILENO);
}

void	ft_display_error_offset(char *program_name, char *offset)
{
	ft_putstr(basename(program_name), STDERR_FILENO);
	ft_putstr(": illegal offset -- ", STDERR_FILENO);
	ft_putstr(offset, STDERR_FILENO);
	ft_putstr("\n", STDERR_FILENO);
}

void	ft_display_header(char *pathname, int flush)
{
	if (flush)
		ft_putstr("\n", STDOUT_FILENO);
	ft_putstr("==> ", STDOUT_FILENO);
	ft_putstr(pathname, STDOUT_FILENO);
	ft_putstr(" <==\n", STDOUT_FILENO);
}
