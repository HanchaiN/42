/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:48:33 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 11:10:19 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *))
{
	int	cmp;

	if (!root)
		return (0);
	cmp = (*cmpf)(root->item, data_ref);
	if (cmp == 0)
		return (root->item);
	else if (cmp > 0)
		return (btree_search_item(root->left, data_ref, cmpf));
	else
		return (btree_search_item(root->right, data_ref, cmpf));
}
