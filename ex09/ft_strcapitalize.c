/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:05:10 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/10 18:09:05 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*str_;
	int		is_word;

	str_ = str;
	is_word = 0;
	while (*str != '\0')
	{
		if (!is_word && 'a' <= *str && *str <= 'z')
			*str += 'A' - 'a';
		if (is_word && 'A' <= *str && *str <= 'Z')
			*str += 'a' - 'A';
		is_word = (
				('A' <= *str && *str <= 'Z')
				|| ('a' <= *str && *str <= 'z')
				|| ('0' <= *str && *str <= '9')
				);
		str++;
	}
	return (str_);
}
