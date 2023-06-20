/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:06:18 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/20 13:10:10 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	t_list_push_back(t_list **begin_list, void *data)
{
	t_list	*curr;

	curr = *begin_list;
	while (curr && curr->next)
		curr = curr->next;
	if (curr)
		curr->next = ft_create_elem(data);
	else
		*begin_list = ft_create_elem(data);
}
