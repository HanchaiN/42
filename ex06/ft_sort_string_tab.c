/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:46:12 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/21 12:03:35 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 < *s2)
			return (-1);
		if (*s1 > *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	char	*temp;
	char	**curr;

	if (!*tab)
		return ;
	curr = tab;
	while (*curr)
	{
		if (ft_strcmp(*tab, *curr) < 0)
		{
			temp = *tab;
			*tab = *curr;
			*curr = temp;
		}
		curr++;
	}
	ft_sort_string_tab(tab + 1);
	return ;
}
