/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:50:19 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/28 13:14:20 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_marker
{
	char			empty;
	char			obstacle;
	char			full;
}					t_marker;
typedef struct s_grid
{
	unsigned int	n;
	unsigned int	m;
	int				**value;
}					t_grid;
typedef struct s_square
{
	unsigned int	x0;
	unsigned int	y0;
	unsigned int	x1;
	unsigned int	y1;
}					t_square;

unsigned int	ft_min(unsigned int *tab, unsigned int count);
int				bsq_parse_header(char *header, t_marker *marker);
t_grid			*bsq_parse_grid(char *content,
					int n_lines, int len_of_line, t_marker markers);
int				check_matrix_chars(char *matr, t_marker markers);
int				check_duplicates(t_marker marker);
t_square		*bsq_find_largest_square(const t_grid *grid);
void			bsq_display_grid(const t_grid *grid, const t_square *square,
					const t_marker marker);
void			bsq_free_grid(t_grid *grid);

#endif
