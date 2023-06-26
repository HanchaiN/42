/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_funcs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:14:47 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/26 11:14:52 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_FUNCS_H
# define BSQ_FUNCS_H

//ONLY FOR DEBUG
# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>


char	*get_content(char *path);
void	ft_putstr(char *str);

#endif
