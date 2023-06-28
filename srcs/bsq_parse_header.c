/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_parse_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:21:25 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/28 09:22:30 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// Count len of single line till \n
int	ft_len_line(char *header)
{
	int	len;

	len = 0;
	while (*header != '\n' && *header != '\0')
	{
		header++;
		len++;
	}
	return (len);
}

// Extract the chars for empty,obstacle and full
// It takes last 3 chars before new line
t_marker	bsq_parse_header_markers(char *header)
{
	t_marker	markers;
	int			len;
	int			i;

	len = ft_len_line(header);
	markers.empty = header[len - 3];
	markers.obstacle = header[len - 2];
	markers.full = header[len - 1];
	return (markers);
}
