/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:49:15 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/25 16:43:32 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "ft_dict.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_get_value(unsigned int key, const char *path)
{
	int		fileno;
	t_entry	*entry;
	char	*str;

	fileno = open(path, O_RDONLY);
	if (fileno < 0)
		return (NULL);
	entry = NULL;
	str = ft_read_line(fileno);
	while (str && (!entry || entry->key != key))
	{
		entry = ft_parse_entry(str);
		str = ft_read_line(fileno);
	}
	if (entry && entry->key == key)
		str = entry->value;
	else
		str = NULL;
	free(entry);
	close(fileno);
	return (str);
}
