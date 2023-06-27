/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:47:05 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/27 10:08:02 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	len_line(char *content)
{
	int	len;

	len = 0;
	while (*content != '\n')
	{
		content++;
	}
	content++;
	while (*content != '\0' && *content != '\n')
	{
		len++;
		content++;
	}
	return (len);
}
