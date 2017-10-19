/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 18:13:57 by tshevchu          #+#    #+#             */
/*   Updated: 2017/07/12 18:52:45 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	find_direct_x_y(t_re *re, int dots, int me_en_x_y[4], t_coord *coord)
{
	int mod;

	mod = 3;
	if (me_en_x_y[0] >= (re->m_x / 3 * re->m_y / 3) / 2)
		me_en_x_y[0] = 1;
	if (me_en_x_y[1] >= (re->m_x / 3 * re->m_y / 3) / 2)
		me_en_x_y[1] = 1;
	if ((coord->my_sq - coord->num_sq) == 0)
		coord->my_sq++;
	if ((coord->my_sq - coord->num_sq) < 0)
		mod = -3;
	if (dots / me_en_x_y[0] * me_en_x_y[1] * mod *
		(coord->my_sq - coord->num_sq) > re->dots)
	{
		re->dots = dots / me_en_x_y[0] * me_en_x_y[1] * mod *
			(coord->my_sq - coord->num_sq);
		re->direct_x = (me_en_x_y[2] + (me_en_x_y[2] + re->m_x / 3)) / 2;
		re->direct_y = (me_en_x_y[3] + (me_en_x_y[3] + re->m_y / 3)) / 2;
	}
}

int		can_put_piece(t_re *re, int x, int y)
{
	int i;
	int j;
	int count;

	count = 0;
	i = -1;
	while (re->p[++i])
	{
		j = -1;
		while (re->p[i][++j])
		{
			if (!re->m[x][y + j])
				return (0);
			else if (re->p[i][j] == '*' && (re->m[x][y + j] ==
					re->l_en || re->m[x][y + j] ==
					ft_toupper(re->l_en)))
				return (0);
			else if (re->p[i][j] == '*' && (re->m[x][y + j] == re->l_me
					|| re->m[x][y + j] == ft_toupper(re->l_me)))
				count++;
		}
		if (!re->m[++x])
			return (0);
	}
	return (count);
}

void	find_first_star(t_re *re, t_coord *coord)
{
	int x;
	int y;

	x = 0;
	while (re->p[x])
	{
		y = 0;
		while (re->p[x][y])
		{
			if (re->p[x][y] == '*')
			{
				coord->star_x = x;
				coord->star_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

int		help_find_min_dist(t_re *re, t_coord *coord, int x_y_min[3])
{
	if (ft_sqrt(((re->direct_x - (x_y_min[0] + coord->star_x)) *
				(re->direct_x - (x_y_min[0] + coord->star_x))) +
				((re->direct_y - (x_y_min[1] + coord->star_y)) *
				(re->direct_y - (x_y_min[1] + coord->star_y)))) < x_y_min[2])
	{
		coord->res_x = x_y_min[0];
		coord->res_y = x_y_min[1];
		x_y_min[2] = ft_sqrt(((re->direct_x - (x_y_min[0] + coord->star_x)) *
							(re->direct_x - (x_y_min[0] + coord->star_x))) +
							((re->direct_y - (x_y_min[1] + coord->star_y)) *
							(re->direct_y - (x_y_min[1] + coord->star_y))));
	}
	return (x_y_min[2]);
}

void	find_min_dist(t_re *re, t_coord *coord)
{
	int x_y_min[3];
	int x;
	int y;
	int res;
	int nb;

	find_first_star(re, coord);
	nb = re->m_x * re->m_x + re->m_y * re->m_y;
	x_y_min[2] = ft_sqrt(nb);
	x = 0;
	while (re->m[x])
	{
		y = 0;
		while (re->m[x][y])
		{
			res = can_put_piece(re, x, y);
			x_y_min[0] = x;
			x_y_min[1] = y;
			if (res == 1)
				x_y_min[2] = help_find_min_dist(re, coord, x_y_min);
			y++;
		}
		x++;
	}
}
