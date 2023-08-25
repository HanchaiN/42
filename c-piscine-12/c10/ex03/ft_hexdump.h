/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:45:33 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/29 09:55:39 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

void	ft_putchar(char ch, int fileno);
void	ft_putstr(char *str, int fileno);
int		ft_strcmp(char *s1, char *s2);
void	ft_write_hex(
			unsigned long long value,
			unsigned int min_count,
			int fileno);
void	ft_write_char(char ch, int fileno);
void	ft_format_error(char *program_name, char *pathname, int status);
void	ft_format_ascii(unsigned long long index, int count, char *buffer);
void	ft_format_hex(unsigned long long index, int count, char *buffer);
int		ft_hexdump(char **argv, char *program_name,
			void (*format)(unsigned long long, int, char *),
			int is_ascii);

#endif