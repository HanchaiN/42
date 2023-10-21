/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:27:17 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/22 01:27:14 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	gnl_append_block(t_gnl_state *state, t_gnl_block *block)
{
	if (state->end_block)
		state->end_block->next = block;
	else
		state->begin_block = block;
	state->end_block = block;
	block->next = NULL;
}

static int	gnl_read_block(t_gnl_state *state)
{
	t_gnl_block	*block;
	ssize_t		i;

	block = malloc(sizeof(t_gnl_block));
	if (!block)
		return (0b10);
	block->len = read(state->fd, block->buffer, BUFFER_SIZE);
	if (block->len <= 0)
	{
		free(block);
		return (0b10);
	}
	gnl_append_block(state, block);
	i = 0;
	while (i < block->len)
	{
		state->len++;
		if (block->buffer[i] == '\n')
			return (0b01);
		i++;
	}
	return (0b00);
}

static char	*gnl_extract_line(t_gnl_state *state)
{
	char		*line;
	ssize_t		i;
	t_gnl_block	*temp;

	line = malloc(sizeof(char) * (state->len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < state->len)
	{
		line[i] = state->begin_block->buffer[state->offset];
		state->offset++;
		i++;
		if (state->offset == state->begin_block->len)
		{
			state->offset = 0;
			temp = state->begin_block;
			if (state->begin_block == state->end_block)
				state->end_block = NULL;
			state->begin_block = state->begin_block->next;
			free(temp);
		}
	}
	line[i] = '\0';
	return (line);
}

static int	gnl_update_state(t_gnl_state *state)
{
	ssize_t	i;

	state->status &= 0b10;
	if (!state->end_block)
	{
		state->len = 0;
		return (state->status & 0b10);
	}
	i = state->offset;
	while (i < state->end_block->len)
	{
		i++;
		if (state->end_block->buffer[i - 1] == '\n')
			break ;
	}
	state->len = i - state->offset;
	state->status |= state->end_block->buffer[i - 1] == '\n';
	return (!state->begin_block && state->status & 0b10);
}

char	*get_next_line(int fd)
{
	t_gnl_state	*state;
	char		*line;

	state = gnl_get_state(fd);
	if (!state || (!state->begin_block && state->status & 0b10))
		return (NULL);
	while (state->status == 0b00)
		state->status |= gnl_read_block(state);
	line = gnl_extract_line(state);
	if (gnl_update_state(state))
		gnl_clear_state(state);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
