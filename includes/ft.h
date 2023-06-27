/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:52:30 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/27 16:09:59 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdlib.h>

int		ft_isdigit(char ch);
int		ft_isspace(char ch);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *src);
char	*ft_strtrim(char *src);
void	ft_putchar(char ch);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putchar_fd(char ch, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);

#endif
