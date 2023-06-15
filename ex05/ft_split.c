/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:11:11 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/15 09:54:15 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	char	**curr;
	char	*substr;

	ret = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1));
	curr = ret;
	while (*str)
	{
		if (ft_strchr(charset, *str))
		{
			str++;
			continue ;
		}
		*curr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		substr = *curr;
		while (*str && !ft_strchr(charset, *str))
			*(substr++) = *(str++);
		*substr = '\0';
		curr++;
	}
	*curr = 0;
	return (ret);
}
