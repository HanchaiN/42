/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:52:30 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/27 10:04:13 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdlib.h>

int				ft_isdigit(char ch);
int				ft_isspace(char ch);
int				ft_atoi(char *str);
void			ft_putchar(char ch);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				ft_strlen(char *str);
char			*ft_strdup(char *src);
char			*ft_strtrim(char *src);
void			*ft_calloc(size_t count, size_t size);
unsigned int	ft_min(unsigned int *tab, unsigned int count);

#endif
