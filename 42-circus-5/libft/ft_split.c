/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:43:51 by hnonpras          #+#    #+#             */
/*   Updated: 2023/08/25 16:03:32 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	free2d(void **ptr)
{
	void	**curr;

	curr = ptr;
	while (*curr)
		free(*(curr++));
	free(ptr);
}

static size_t	split_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static size_t	split_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	char	**curr;

	ret = (char **)malloc((split_count(s, c) + 1) * sizeof(char *));
	if (!ret)
		return (ret);
	curr = ret;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			break ;
		*curr = ft_substr(s, 0, split_len(s, c));
		if (!*curr)
		{
			free2d((void **)ret);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		curr++;
	}
	*curr = NULL;
	return (ret);
}
