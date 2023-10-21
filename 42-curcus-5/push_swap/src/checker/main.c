/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:32:12 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/14 14:42:08 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

static int	ps_init(int argc, char *argv[], t_data *stack)
{
	int	i;
	int	*val;

	stack->a = NULL;
	stack->b = NULL;
	i = 0;
	while (i < argc)
	{
		val = malloc(sizeof(int));
		// TODO: check if argv[i] is a valid number
		*val = ft_atoi(argv[i++]);
		// TODO: check duplicates
		ft_lstadd_back(&(stack->a), ft_lstnew(val));
	}
	return (0);
}

static void	ps_check(const t_data *stack)
{
	t_list	*tmp;

	if (stack->b)
	{
		ft_putendl_fd("KO", STDOUT_FILENO);
		return ;
	}
	tmp = stack->a;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
		{
			ft_putendl_fd("KO", STDOUT_FILENO);
			return ;
		}
		tmp = tmp->next;
	}
	ft_putendl_fd("OK", STDOUT_FILENO);
}

static void	ps_free(t_data *stack)
{
	ft_lstclear(&stack->a, free);
	ft_lstclear(&stack->b, free);
	free(stack);
	gnl_clear_buffer(STDIN_FILENO);
}

static int	main_prototype(int argc, char *argv[], t_data *stack,
		int is_verbose)
{
	int		ret;
	char	*operation;

	if (argc == 0)
		return (0);
	if (stack == NULL)
		return (-1);
	ret = ps_init(argc, argv, stack);
	if (ret)
		return (ret);
	ps_display_stack(stack, is_verbose);
	operation = get_next_line(STDIN_FILENO);
	while (operation)
	{
		ret = ps_operate(stack, operation);
		free(operation);
		if (ret)
			return (ret);
		ps_display_stack(stack, is_verbose);
		operation = get_next_line(STDIN_FILENO);
	}
	ps_check(stack);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data *stack;
	int ret;

	ret = 0;
	stack = malloc(sizeof(t_data));
	if (argc > 1 && ft_strncmp(argv[1], "-v", 3) == 0)
		ret |= main_prototype(argc - 2, argv + 2, stack, 1);
	else
		ret |= main_prototype(argc - 1, argv + 1, stack, 0);
	if (ret)
		ft_putendl_fd("Error", STDERR_FILENO);
	ps_free(stack);
	return (ret);
}