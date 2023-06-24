/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 08:47:53 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/24 19:08:38 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include <libgen.h>

int	main(int argc, char **argv)
{
	char	*program_name;

	program_name = basename(argv[0]);
	if (argc > 1 && ft_strcmp(argv[1], "-C") == 0)
		return (ft_hexdump(argv + 2, program_name, ft_format_ascii));
	else
		return (ft_hexdump(argv + 1, program_name, ft_format_hex));
}
