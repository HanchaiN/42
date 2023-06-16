/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscraper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnonpras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:39:38 by hnonpras          #+#    #+#             */
/*   Updated: 2023/06/16 11:41:47 by hnonpras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SKYSCRAPER_H
# define FT_SKYSCRAPER_H

typedef struct s_projection
{
	int	n;
	int	*top;
	int	*down;
	int	*left;
	int	*right;
}				t_projection;

#endif
