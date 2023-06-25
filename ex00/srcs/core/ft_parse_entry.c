/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:49:15 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/25 14:17:57 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_dict.h"
#include <stdlib.h>
#include <string.h>

t_entry	*ft_parse_entry(char *line)
{
    t_entry *entry;

    entry = (t_entry *) malloc(sizeof(t_entry));
    entry->key = atoi(line);
    line = strchr(line, ':');
    if (*line != ':')
    {
        free(entry);
        return (NULL);
    }
    line++;
    entry->value = ft_strtrim(line);
    line++;
    return (entry);
}
