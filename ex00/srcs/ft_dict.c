/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:54:32 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/24 15:02:17 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_buffer.h"
#include "ft_dict.h"

int	main(int argc, char **argv)
{
	t_buffer	*buffer;

	(void) argc;
	(void) argv;
	buffer = ft_buffer_new(0);
	ft_put_number(429496729, "", buffer);
	ft_buffer_print(buffer);
	ft_buffer_free(buffer);
	ft_putchar('\n');
	ft_putstr((char *) g_default_dict);
	return (0);
}
