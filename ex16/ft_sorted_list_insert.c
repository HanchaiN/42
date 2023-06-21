/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:49:49 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/21 09:58:39 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;
	t_list	*curr;

	elem = ft_create_elem(data);
	if (!*begin_list || (*cmp)((*begin_list)->data, elem->data) >= 0)
	{
		elem->next = *begin_list;
		*begin_list = elem;
		return ;
	}
	curr = *begin_list;
	while (curr && curr->next)
	{
		if ((*cmp)(curr->next->data, elem->data) >= 0)
		{
			elem->next = curr->next;
			curr->next = elem;
			return ;
		}
		curr = curr->next;
	}
	curr->next = elem;
}
