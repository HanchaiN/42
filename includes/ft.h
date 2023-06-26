/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:52:30 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 15:00:15 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <sys/types.h>

void			ft_putchar(char ch);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
char			*ft_strdup(char *src);
char			*ft_strtrim(char *src);
void			*ft_calloc(size_t count, size_t size);	
unsigned int	ft_min(unsigned int *tab, unsigned int count);

#endif
