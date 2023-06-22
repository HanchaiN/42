/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:46:12 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/22 14:32:45 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*temp;
	char	**curr;
	int		swapped;

	swapped = 1;
	curr = tab;
	while (swapped)
	{
		swapped = 0;
		while (*curr)
		{
			if ((*cmp)(*tab, *curr) > 0)
			{
				swapped = 1;
				temp = *tab;
				*tab = *curr;
				*curr = temp;
			}
			curr++;
		}
	}
}
