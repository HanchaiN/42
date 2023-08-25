/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:06:18 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/20 13:45:25 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*curr;

	curr = *begin_list1;
	while (curr && curr->next)
		curr = curr->next;
	if (curr)
		curr->next = begin_list2;
	else
		*begin_list1 = begin_list2;
}
