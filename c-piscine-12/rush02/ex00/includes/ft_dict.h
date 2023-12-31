/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:50:33 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/25 19:39:52 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_H
# define FT_DICT_H
# include "ft_buffer.h"

typedef struct s_entry
{
	unsigned int	key;
	char			*value;
}					t_entry;

char				*ft_get_value(unsigned int key, const char *path);
t_entry				*ft_parse_entry(char *line);
void				ft_free_entry(t_entry *entry);
int					ft_put_value(unsigned int key, const char *path,
						t_buffer *buffer);
unsigned int		ft_parse_number(char string[], int *error_flag);
int					ft_put_number(unsigned int nbr, const char *path,
						t_buffer *buffer);

char				*ft_read_line(int fileno);

extern const char	*g_default_dict;

#endif
