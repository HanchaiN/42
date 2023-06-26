/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:50:19 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/26 15:00:11 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <sys/types.h>

typedef struct s_square
{
	unsigned int	x0;
	unsigned int	y0;
	unsigned int	x1;
	unsigned int	y1;
}	t_square;

t_square	*bsq_find_largest_square(size_t x, size_t y, const int **grid);

#endif
