/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:40:44 by tshevchu          #+#    #+#             */
/*   Updated: 2017/07/14 14:20:12 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	count_dots(t_re *re, int x, int y, t_coord *coord)
{
	int me_en_x_y[4];
	int j;
	int i;
	int dots;

	i = x - 1;
	me_en_x_y[0] = 1;
	me_en_x_y[1] = 1;
	dots = 0;
	while (++i < x + re->m_x / 3)
	{
		j = y - 1;
		while (++j < y + re->m_y / 3)
		{
			if (re->m[i][j] == '.')
				dots++;
			if (re->m[i][j] == re->l_me || re->m[i][j] == ft_toupper(re->l_me))
				(me_en_x_y[0])++;
			if (re->m[i][j] == re->l_en || re->m[i][j] == ft_toupper(re->l_en))
				(me_en_x_y[1])++;
		}
	}
	me_en_x_y[2] = x;
	me_en_x_y[3] = y;
	find_direct_x_y(re, dots, me_en_x_y, coord);
}

void	squares(t_re *re, t_coord *coord)
{
	int x;
	int y;
	int k;

	k = 0;
	x = 0;
	while (x < 5 * re->m_x / 6)
	{
		y = 0;
		while (y < 5 * re->m_y / 6)
		{
			k++;
			coord->num_sq = k;
			count_dots(re, x, y, coord);
			y = y + re->m_y / 3;
		}
		x = x + re->m_x / 3;
	}
}

void	find_my_square(t_coord *coord, t_re *re)
{
	int x;
	int sq;
	int y;

	sq = 0;
	x = 0;
	while (x < 5 * re->m_x / 6)
	{
		y = 0;
		while (y < 5 * re->m_y / 6)
		{
			sq++;
			if (coord->me_x > x && coord->me_x < x + re->m_x / 3)
			{
				if (coord->me_y > y && coord->me_y < y + re->m_y / 3)
					coord->my_sq = sq;
			}
			y = y + re->m_y / 3;
		}
		x = x + re->m_x / 3;
	}
}

void	print_coord(t_coord *coord)
{
	if (coord->res_x != -1 && coord->res_y != -1)
		ft_printf("%d %d\n", coord->res_x, coord->res_y);
	else
		ft_printf("%d %d\n", -1, -1);
}

void	find_direction(t_re *re)
{
	t_coord *coord;

	coord = init_coord();
	where_am_i(re, coord);
	find_my_square(coord, re);
	squares(re, coord);
	strategy_for_o_small(re);
	strategy_for_x_small(re);
	strategy_for_x_aver(re);
	find_min_dist(re, coord);
	print_coord(coord);
	free(coord);
}
