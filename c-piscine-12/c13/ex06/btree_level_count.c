/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:11:20 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 11:13:26 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	countl;
	int	countr;

	if (!root)
		return (0);
	countl = 0;
	countr = 0;
	if (root->left)
		countl = btree_level_count(root->left) + 1;
	if (root->right)
		countr = btree_level_count(root->right) + 1;
	if (countl > countr)
		return (countl);
	else
		return (countr);
}