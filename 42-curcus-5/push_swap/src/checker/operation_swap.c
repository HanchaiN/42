/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:32:29 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 13:45:49 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ps_swap_a(t_data *stack)
{
	return (ps_swap(&stack->a));
}

int	ps_swap_b(t_data *stack)
{
	return (ps_swap(&stack->b));
}

int	ps_swap_s(t_data *stack)
{
	int ret;

	ret = 0;
	ret |= ps_swap(&stack->a);
	ret |= ps_swap(&stack->b);
	return (ret);
}