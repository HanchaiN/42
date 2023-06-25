/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:50:33 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/25 14:05:58 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFER_H
# define FT_BUFFER_H

typedef struct s_buffer
{
	char			*begin;
	char			*curr;
	unsigned int	capacity;
}					t_buffer;

t_buffer			*ft_buffer_new(unsigned int capacity);
void				ft_buffer_free(t_buffer *buffer);
void				ft_buffer_extend(t_buffer *buffer);
void				ft_buffer_putchar(char ch, t_buffer *buffer);
void				ft_buffer_putstr(char *str, t_buffer *buffer);
char				*ft_buffer_strdup(t_buffer *buffer);
void				ft_buffer_print(t_buffer *buffer);

#endif
