/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:52:30 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/25 19:34:42 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int				ft_isspace(char ch);
void			ft_putchar(char ch);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
char			*ft_strdup(char *src);
char			*ft_strtrim(char *src);
unsigned int	ft_atoi_uint(char *str);

#endif
