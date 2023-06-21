/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:46:12 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/21 13:05:07 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*temp;
	char	**curr;

	if (!*tab)
		return ;
	curr = tab;
	while (*curr)
	{
		if ((*cmp)(*tab, *curr) > 0)
		{
			temp = *tab;
			*tab = *curr;
			*curr = temp;
		}
		curr++;
	}
	ft_advanced_sort_string_tab(tab + 1, cmp);
	return ;
}
