/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:32:32 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 14:05:59 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int	ps_operate(t_data *stack, const char *operation)
{
	const t_operation op[] = {
		{.op = ps_swap_a, .name = "sa\n"},
		{.op = ps_swap_b, .name = "sb\n"},
		{.op = ps_swap_s, .name = "ss\n"},
		{.op = ps_push_a, .name = "pa\n"},
		{.op = ps_push_b, .name = "pb\n"},
		{.op = ps_rotate_a, .name = "ra\n"},
		{.op = ps_rotate_b, .name = "rb\n"},
		{.op = ps_rotate_r, .name = "rr\n"},
		{.op = ps_reverse_rotate_a, .name = "rra\n"},
		{.op = ps_reverse_rotate_b, .name = "rrb\n"},
		{.op = ps_reverse_rotate_r, .name = "rrr\n"},
	};
	size_t i;

	i = 0;
	while (i < (sizeof(op) / sizeof(t_operation)))
	{
		if (ft_strncmp(op[i].name, operation, 4) == 0)
			return (op[i].op(stack));
		i++;
	}
	return (-1);
}