/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:39:38 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/16 15:48:00 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SKYSCRAPER_H
# define FT_SKYSCRAPER_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_input
{
	int	n;
	int	*top;
	int	*bottom;
	int	*left;
	int	*right;
}				t_input;

typedef struct s_state
{
	int				i;
	int				j;
	int				**height;
}				t_state;

typedef struct s_column
{
	int	n;
	int	l_count;
	int	r_count;
	int	*height;
}				t_column;

typedef struct s_range
{
	int	min;
	int	max;
}				t_range;

void	free_input(t_input data);
int		**malloc2d(int x, int y);
void	free2d(int **arr, int x, int y);
int		*get_row(int **arr, int x, int j);
int		*rev_arr(int *arr, int size);
t_input	parse_input(char *inp);
int		is_valid(const t_input *constraint, t_state *state);
int		**find_solution(t_input *constraint);
void	print_board(int n, int **board);
int		print_error(int cide);

#endif
