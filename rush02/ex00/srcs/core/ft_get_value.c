/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:49:15 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/25 19:40:43 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
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
		ft_free_entry(entry);
		entry = ft_parse_entry(str);
		free(str);
		str = ft_read_line(fileno);
	}
	free(str);
	if (entry && entry->key == key)
		str = ft_strdup(entry->value);
	else
		str = NULL;
	ft_free_entry(entry);
	close(fileno);
	return (str);
}
