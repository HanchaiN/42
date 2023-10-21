/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <hnonpras@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:22:44 by hnonpras          #+#    #+#             */
/*   Updated: 2023/10/22 01:25:13 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_gnl_block
{
	char				buffer[BUFFER_SIZE];
	ssize_t				len;
	struct s_gnl_block	*next;
}						t_gnl_block;

typedef struct s_gnl_state
{
	int					fd;
	int					status;
	ssize_t				len;
	ssize_t				offset;
	t_gnl_block			*begin_block;
	t_gnl_block			*end_block;
	struct s_gnl_state	*next;
	struct s_gnl_state	*prev;
}						t_gnl_state;

t_gnl_state				*gnl_get_state(int fd);
void					gnl_clear_state(t_gnl_state *state);

void					gnl_clear_var(void);
char					*get_next_line(int fd);

#endif
