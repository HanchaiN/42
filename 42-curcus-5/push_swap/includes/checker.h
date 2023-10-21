/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:31:39 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 14:41:17 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"

typedef struct s_data
{
	t_list	*a;
	t_list	*b;
}			t_data;
typedef struct s_operation
{
	int		(*op)(t_data *);
	char	name[5];
}			t_operation;

int			ps_swap(t_list **stack);
int			ps_push(t_list **from, t_list **to);
int			ps_rotate(t_list **stack);
int			ps_reverse_rotate(t_list **stack);

int			ps_swap_a(t_data *stack);
int			ps_swap_b(t_data *stack);
int			ps_swap_s(t_data *stack);
int			ps_push_a(t_data *stack);
int			ps_push_b(t_data *stack);
int			ps_rotate_a(t_data *stack);
int			ps_rotate_b(t_data *stack);
int			ps_rotate_r(t_data *stack);
int			ps_reverse_rotate_a(t_data *stack);
int			ps_reverse_rotate_b(t_data *stack);
int			ps_reverse_rotate_r(t_data *stack);

int			ps_operate(t_data *stack, const char *operation);

void		ps_display_stack(const t_data *stack, int is_display);

#endif