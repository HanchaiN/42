/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:27:17 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/21 18:12:51 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl_list	*gnl_get_buffer(int fd)
{
	static t_gnl_list	*list;
	t_gnl_list			*current;

	current = list;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current = malloc(sizeof(t_gnl_list));
	if (!current)
		return (NULL);
	current->fd = fd;
	current->buff = NULL;
	current->next = list;
	list = current;
	return (current);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned const char	*src_;
	unsigned char		*dst_;

	if (dest == src)
		return (dest);
	src_ = (unsigned const char *)src;
	dst_ = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		dst_[i] = src_[i];
		i++;
	}
	return (dest);
}

static int	gnl_append(char **line, int *len, t_gnl_list *node)
{
	char	*new_line;
	int		i;

	i = node->start;
	while (i + 1 < node->len && node->buff[i] != '\n')
		i++;
	new_line = malloc((*len + i - node->start + 1) * sizeof(char));
	if (!new_line)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	ft_memcpy(new_line, *line, *len);
	ft_memcpy(new_line + *len, node->buff + node->start, i - node->start + 1);
	new_line[*len + i - node->start + 1] = '\0';
	free(*line);
	*line = new_line;
	*len += i - node->start + 1;
	node->start = i + 1;
	if (node->start >= node->len)
		free(node->buff);
	if (node->start >= node->len)
		node->buff = NULL;
	return ((*line)[*len - 1] == '\n');
}

static char	*gnl_read_line(t_gnl_list *node)
{
	char	*line;
	int		len;

	line = malloc(1 * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	len = 0;
	while (1)
	{
		if (node->buff == NULL)
		{
			node->start = 0;
			node->buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
			if (!node->buff)
				return (NULL);
			node->len = read(node->fd, node->buff, BUFFER_SIZE);
			if (node->len <= 0)
			{
				if (node->len < 0 || len == 0)
				{
					free(line);
					line = NULL;
				}
				free(node->buff);
				node->buff = NULL;
				return (line);
			}
			else
				node->buff[node->len] = '\0';
		}
		if (node->len == 0 || gnl_append(&line, &len, node))
			return (line);
	}
}

char	*get_next_line(int fd)
{
	t_gnl_list	*current;
	char		*line;

	current = gnl_get_buffer(fd);
	if (!current)
		return (NULL);
	line = gnl_read_line(current);
	if (!line)
	{
		free(current->buff);
		current->buff = NULL;
	}
	return (line);
}
