/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:54:32 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/24 11:35:38 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "ft_dict.h"

int	main(int argc, char **argv)
{
	t_buffer	*buffer;

	(void) argc;
	(void) argv;
	buffer = ft_buffer_new(1);
	ft_buffer_putstr("abcdefghijklmnopqrstuvwxyz", buffer);
	ft_buffer_print(buffer);
	ft_buffer_free(buffer);
	return (0);
}
