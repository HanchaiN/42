/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:39:38 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/18 14:46:43 by hnonpras         ###   ########.fr       */
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
	int	**height_ptr;
	int	*possible;
	int	possible_size;
}				t_column;

typedef struct s_state
{
	int			i;
	int			j;
	int			n;
	int			**height;
	t_column	*col;
	t_column	*rows;
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
int		factorial(int n);
int		*get_perm(int size, int ind);
int		generate_possible_columns(t_column *col);
int		parse_constraint(t_constraint *constraint, const char *inp);
void	free_constraint(t_constraint *constraint);
int		init_state(t_state *state, const t_constraint *constraint);
void	free_state(t_state *state);
int		get_count_left(int *column, int n);
int		get_count_right(int *column, int n);
t_range	get_count_range_left(int index, const t_column *column);
t_range	get_count_range_right(int index, const t_column *column);
int		is_valid(t_state *state);
int		eliminate(t_state *state, int n);
int		backtrack(t_state *state);
int		find_solution(t_state *state);
void	print_board(int n, int **board);
int		print_error(int code);

#endif
