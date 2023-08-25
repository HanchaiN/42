/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileio.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:53:15 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/27 16:10:37 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILEIO_H
# define FT_FILEIO_H
# include <stdlib.h>

size_t	ft_get_file_size(char *path);
char	*ft_read_line(int fileno);
char	*ft_read_file(char *path);

#endif