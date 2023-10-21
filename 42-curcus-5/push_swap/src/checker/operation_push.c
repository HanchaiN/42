/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:32:18 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 13:45:36 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ps_push_a(t_data *stack)
{
	return (ps_push(&stack->b, &stack->a));
}

int	ps_push_b(t_data *stack)
{
	return (ps_push(&stack->a, &stack->b));
}