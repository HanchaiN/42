/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_parse_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:21:25 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/28 11:28:59 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// Extract the chars for empty,obstacle and full
// It takes last 3 chars before new line
int	bsq_parse_header(char *header, t_marker *marker)
{
	int			len;
	int			n;

	len = ft_strlen(header);
	if (header[len - 1] == '\n')
		len--;
	if (len < 4)
		return (-1);
	marker->empty = header[len - 3];
	marker->obstacle = header[len - 2];
	marker->full = header[len - 1];
	header[len - 3] = 0;
	n = ft_atoi(header);
	return (n);
}
