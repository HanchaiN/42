/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:10:40 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/20 13:12:56 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin_list;
	t_list	*elem;
	int		i;

	begin_list = NULL;
	i = 0;
	while (i < size)
	{
		elem = ft_create_elem(strs[i]);
		elem->next = begin_list;
		begin_list = elem;
	}
	return (begin_list);
}
