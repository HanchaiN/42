/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:17:29 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/28 13:58:06 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

void	ft_putstr(char *str, int fileno);
int		ft_atoi(char *str, char *program_name);
void	ft_display_error_errno(char *program_name, char *pathname, int status);
void	ft_display_error_offset(char *program_name, char *offset);
void	ft_display_header(char *pathname);
int		ft_tail(int fileno, int byte_count);
int		ft_tail_file(char *pathname, int byte_count, int show_header);
int		ft_tail_stdin(int byte_count);

#endif
