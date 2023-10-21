/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:32:32 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 14:43:51 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

static void	ps_display_node(t_list **node, int is_display)
{
	if (!is_display)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		return ;
	}
	ft_putnbr_fd(*(int *)(*node)->content, STDOUT_FILENO);
	(*node) = (*node)->next;
}

void	ps_display_stack(const t_data *stack, int is_display)
{
	int		la;
	int		lb;
	int		len;
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (!is_display)
		return ;
	tmp_a = stack->a;
	tmp_b = stack->b;
	la = ft_lstsize(tmp_a);
	lb = ft_lstsize(tmp_b);
	if (la > lb)
		len = la;
	else
		len = lb;
	ft_putendl_fd("-----", STDOUT_FILENO);
	while (len--)
	{
		ps_display_node(&tmp_a, len < la);
		ft_putchar_fd(' ', STDOUT_FILENO);
		ps_display_node(&tmp_b, len < lb);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	ft_putendl_fd("- -\na b\n-----", STDOUT_FILENO);
}
