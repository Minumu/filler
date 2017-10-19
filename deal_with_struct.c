/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:55:43 by tshevchu          #+#    #+#             */
/*   Updated: 2017/07/12 18:53:30 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_re		*create_empty_struct(void)
{
	t_re *empty;

	empty = malloc(sizeof(t_re));
	empty->m_x = 0;
	empty->m_y = 0;
	empty->m = NULL;
	empty->p_x = 0;
	empty->p_y = 0;
	empty->p = NULL;
	empty->direct_x = 0;
	empty->direct_y = 0;
	empty->dots = 0;
	empty->move = 0;
	empty->l_me = '-';
	empty->l_en = '-';
	return (empty);
}

void		new_struct(t_re *re)
{
	clean_map(re);
	clean_piece(re);
	re->m = NULL;
	re->p = NULL;
	re->p_x = 0;
	re->p_y = 0;
	re->direct_x = 0;
	re->direct_y = 0;
	re->dots = 0;
}

t_coord		*init_coord(void)
{
	t_coord *coord;

	coord = malloc(sizeof(t_coord));
	coord->me_x = -1;
	coord->me_y = -1;
	coord->res_x = -1;
	coord->res_y = -1;
	coord->star_x = -1;
	coord->star_y = -1;
	coord->my_sq = 0;
	coord->num_sq = 0;
	return (coord);
}

void		clean_piece(t_re *re)
{
	int i;

	i = 0;
	if (re->p == NULL)
		return ;
	else
	{
		while (re->p[i])
		{
			ft_strdel(&re->p[i]);
			i++;
		}
		free(re->p);
	}
}

void		clean_map(t_re *re)
{
	int i;

	i = 0;
	if (re->m == NULL)
		return ;
	else
	{
		while (re->m[i])
		{
			ft_strdel(&re->m[i]);
			i++;
		}
		free(re->m);
	}
}
