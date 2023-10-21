/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:32:15 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 14:23:59 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ps_swap(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) < 2)
		return (0);
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
	return (0);
}

int	ps_push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!*from)
		return (0);
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	return (0);
}

int	ps_rotate(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) < 2)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstlast(*stack)->next = tmp;
	tmp->next = NULL;
	return (0);
}

int	ps_reverse_rotate(t_list **stack)
{
	t_list *tmp;

	if (ft_lstsize(*stack) < 2)
		return (0);
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	return (0);
}