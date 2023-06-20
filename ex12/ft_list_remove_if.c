/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:21:32 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/20 13:40:19 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
			void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*curr;

	prev = NULL;
	while (*begin_list)
	{
		if ((*cmp)((*begin_list)->data, data_ref) != 0)
			break ;
		*begin_list = (*begin_list)->next;
	}
	curr = *begin_list;
	while (curr)
	{
		if ((*cmp)(curr->data, data_ref) == 0)
		{
			prev->next = curr->next;
			free_fct(curr->data);
			free(curr);
			curr = prev;
		}
		prev = curr;
		curr = curr->next;
	}
}
