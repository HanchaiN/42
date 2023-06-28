/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_parse_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:21:25 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/28 13:19:03 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"

/** Parse header line.
 * @param header the header line.
 * @param marker pointer to marker object (output).
 * @return number of content lines.
*/

// Check header that there are no extra chars
// between numbers and 3 last chars

int	ft_lenline(char *str)
{
	int	len;

	len = 0;
	while (*str != '\n' && *str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

int	check_extra_chars(char *header)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lenline(header);
	if (!ft_isdigit(header[i]))
		return (0);
	while (ft_isdigit(header[i]) && header[i] != header[len - 3])
	{
		i++;
	}
	return (header[i] == header[len - 3]
		&& header[i + 1] == header[len - 2]
		&& header[i + 2] == header[len - 1]);
}


int	bsq_parse_header(char *header, t_marker *marker)
{
	int	len;
	int	n;

	len = ft_strlen(header);
	if (header[len - 1] == '\n')
		len--;
	if (len < 4)
		return (-1);
	if (!check_extra_chars(header))
		return (-1);
	marker->empty = header[len - 3];
	marker->obstacle = header[len - 2];
	marker->full = header[len - 1];
	header[len - 3] = 0;
	n = ft_atoi(header);
	return (n);
}
