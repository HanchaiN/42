/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:32:21 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 13:45:40 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ps_reverse_rotate_a(t_data *stack)
{
	return (ps_reverse_rotate(&stack->a));
}

int	ps_reverse_rotate_b(t_data *stack)
{
	return (ps_reverse_rotate(&stack->b));
}

int	ps_reverse_rotate_r(t_data *stack)
{
	int ret;

	ret = 0;
	ret |= ps_reverse_rotate(&stack->a);
	ret |= ps_reverse_rotate(&stack->b);
	return (ret);
}