/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <nonpras@student.42bangkok.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:50:33 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/23 15:57:32 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_H
# define FT_DICT_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_get_value(unsigned int key, char *path);
char	*ft_set_value(unsigned int key, char *value, char *path);
char	*ft_parse(unsigned int key, char *path);

#endif
