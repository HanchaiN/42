/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:44:26 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/20 16:03:47 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DO_OP_H
# define FT_DO_OP_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		operate(int value1, int value2, char *operateur, int *ret);

int		ft_add(int value1, int value2, int *ret);
int		ft_sub(int value1, int value2, int *ret);
int		ft_div(int value1, int value2, int *ret);
int		ft_mul(int value1, int value2, int *ret);
int		ft_mod(int value1, int value2, int *ret);

#endif