/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:42:10 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/22 01:26:03 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_gnl_state	**gnl_get_var(void)
{
	static t_gnl_state	*list = NULL;

	return (&list);
}

t_gnl_state	*gnl_get_state(int fd)
{
	t_gnl_state	*curr;

	curr = *gnl_get_var();
	while (curr)
	{
		if (curr->fd == fd)
			return (curr);
		curr = curr->next;
	}
	curr = malloc(sizeof(t_gnl_state));
	if (!curr)
		return (NULL);
	curr->fd = fd;
	curr->status = 0;
	curr->len = 0;
	curr->offset = 0;
	curr->begin_block = NULL;
	curr->end_block = NULL;
	curr->prev = NULL;
	curr->next = *gnl_get_var();
	if (*gnl_get_var())
		(*gnl_get_var())->prev = curr;
	*gnl_get_var() = curr;
	return (curr);
}

void	gnl_clear_state(t_gnl_state *state)
{
	if (state->prev)
		state->prev->next = state->next;
	else
		*gnl_get_var() = state->next;
	if (state->next)
		state->next->prev = state->prev;
	free(state);
}

void	gnl_clear_var(void)
{
	t_gnl_state	*curr;
	t_gnl_state	*temp;

	curr = *gnl_get_var();
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		gnl_clear_state(temp);
	}
	*gnl_get_var() = NULL;
}
