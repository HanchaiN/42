/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:26:45 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/10 14:50:45 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int ft_atoi(const char *str)
{
	int	val;
	int is_negative;
	
	is_negative = *str == '-';
	if (is_negative)
		str++;
	val = 0;
	while ('0' <= *str && *str <= '9')
	{
		val *= 10;
		if (is_negative)
			val -= *str - '0';
		else
			val += *str - '0';
		str++;
	}
	return (val);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		rush(5, 5);
	else
		rush(ft_atoi(*(argv + 1)), ft_atoi(*(argv + 2)));
	return (0);
}
