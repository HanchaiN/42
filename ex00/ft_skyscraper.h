/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:39:38 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/17 17:57:37 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SKYSCRAPER_H
# define FT_SKYSCRAPER_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_constraint
{
	int	n;
	int	*top;
	int	*bottom;
	int	*left;
	int	*right;
}				t_constraint;

typedef struct s_column
{
	int	n;
	int	l_count;
	int	r_count;
	int	**height;
}				t_column;

typedef struct s_state
{
	int			i;
	int			j;
	int			**height;
	t_column	*col;
	t_column	*row;
}				t_state;

typedef struct s_range
{
	int	min;
	int	max;
}				t_range;

int		**malloc2d(int x, int y);
void	free2d(int **arr, int x, int y);
int		is_in_range(const int value, const t_range range);
int		count_1s(int binary);
int		*rev_arr(int *arr, int size);
int		init_state(t_state *state, const t_constraint *constraint);
void	free_state(t_state *state, const t_constraint *constraint);
int		parse_constraint(t_constraint *constraint, const char *inp);
void	free_constraint(t_constraint *constraint);
int		is_valid(t_state *state);
t_state	*find_solution(const t_constraint *constraint);
void	print_board(int n, int **board);
void	print_column(const t_column *col);
int		print_error(int code);

#endif
