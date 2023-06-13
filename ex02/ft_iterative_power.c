/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:43:12 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/13 11:44:35 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	val;
	int	i;

	if (power < 0)
		return (0);
	val = 1;
	i = 0;
	while (i < power)
	{
		val *= nb;
		i++;
	}
	return (val);
}
