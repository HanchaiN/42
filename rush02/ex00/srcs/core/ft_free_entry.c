/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:49:15 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/25 19:41:11 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_dict.h"
#include <stdlib.h>
#include <string.h>

void	ft_free_entry(t_entry *entry)
{
	if (entry)
		free(entry->value);
	free(entry);
}
