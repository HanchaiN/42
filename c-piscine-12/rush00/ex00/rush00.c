/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:26:13 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/10 14:49:11 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j++ < y)
	{
		i = 0;
		while (i++ < x)
		{
			if ((i == 1 && j == 1)
				|| (i == 1 && j == y)
				|| (i == x && j == 1)
				|| (i == x && j == y))
				ft_putchar('o');
			else if (i == 1 || i == x)
				ft_putchar('|');
			else if (j == 1 || j == y)
				ft_putchar('-');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	return ;
}
