/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_parse_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:21:25 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/27 14:47:45 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/** Extract the markers from the header line
 * @param header header line (without the newline)
*/
t_marker	bsq_parse_header_markers(char *header)
{
	t_marker	markers;

	while (ft_isdigit(*header))
		header++;
	markers.empty = *header;
	header++;
	markers.obstacle = *header;
	header++;
	markers.full = *header;
	return (markers);
}
