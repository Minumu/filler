/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:06:44 by tshevchu          #+#    #+#             */
/*   Updated: 2017/07/14 14:22:41 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	strategy_for_o_small(t_re *re)
{
	if (re->m_x == 15 && re->m_y == 17 && re->l_me == 'o')
	{
		if (re->move < 15)
		{
			re->direct_x = 6;
			re->direct_y = 18;
			re->move++;
		}
		else if (re->move >= 15 && re->move < 19)
		{
			re->direct_x = 3;
			re->direct_y = 0;
			re->move++;
		}
	}
}

void	strategy_for_x_small(t_re *re)
{
	if (re->m_x == 15 && re->m_y == 17 && re->l_me == 'x')
	{
		if (re->move < 20)
		{
			re->direct_x = 0;
			re->direct_y = 0;
			re->move++;
		}
		else if (re->move >= 20 && re->move < 23)
		{
			re->direct_x = 12;
			re->direct_y = 14;
			re->move++;
		}
	}
}

void	strategy_for_x_aver(t_re *re)
{
	if (re->m_x == 24 && re->m_y == 40 && re->l_me == 'x')
	{
		if (re->move < 20)
		{
			re->direct_x = 18;
			re->direct_y = 0;
			re->move++;
		}
		else if (re->move >= 20 && re->move < 40)
		{
			re->direct_x = 5;
			re->direct_y = 40;
			re->move++;
		}
		else if (re->move >= 40 && re->move < 50)
		{
			re->direct_x = 0;
			re->direct_y = 2;
			re->move++;
		}
	}
}

void	find_my_coord(t_coord *coord, int x, int y)
{
	if (coord->me_x == -1 && coord->me_y == -1)
	{
		coord->me_x = x;
		coord->me_y = y;
	}
}

void	where_am_i(t_re *re, t_coord *coord)
{
	int x;
	int y;

	x = 0;
	while (re->m[x])
	{
		y = 0;
		while (re->m[x][y])
		{
			if (re->m[x][y] == re->l_me ||
				re->m[x][y] == ft_toupper(re->l_me))
				find_my_coord(coord, x, y);
			y++;
		}
		x++;
	}
}
