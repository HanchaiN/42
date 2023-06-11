/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:43:14 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/11 12:44:10 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*begin;
	char	*curr;
	char	*curr_find;

	begin = str;
	while (*begin != '\0')
	{
		curr = begin;
		curr_find = to_find;
		while (*curr_find != '\0' && *curr == *curr_find)
		{
			curr++;
			curr_find++;
		}
		if (*curr_find == '\0')
			return (begin);
		begin++;
	}
	return (NULL);
}
