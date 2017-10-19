/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:43:03 by tshevchu          #+#    #+#             */
/*   Updated: 2017/07/14 14:47:42 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/includes/libft.h"

typedef struct		s_re
{
	char			**m;
	char			**p;
	int				m_x;
	int				m_y;
	int				p_x;
	int				p_y;
	int				direct_x;
	int				direct_y;
	int				dots;
	int				move;
	char			l_me;
	char			l_en;
}					t_re;

typedef struct		s_coord
{
	int me_x;
	int me_y;
	int star_x;
	int star_y;
	int res_x;
	int res_y;
	int my_sq;
	int num_sq;
}					t_coord;

void				read_map(t_re *re, char *line, int fd);
void				read_piece(t_re *re, int fd, char *line);
t_re				*create_empty_struct(void);
t_coord				*init_coord(void);
void				clean_piece(t_re *re);
void				clean_map(t_re *re);
int					ft_new_atoi(char *str, int i);
int					while_digits(int nb);
int					ft_sqrt(int nb);
void				find_my_coord(t_coord *coord, int x, int y);
void				where_am_i(t_re *re, t_coord *coord);
void				new_struct(t_re *re);
void				find_direction(t_re *re);
void				strategy_for_o_small(t_re *re);
void				strategy_for_x_small(t_re *re);
void				strategy_for_x_aver(t_re *re);
void				find_min_dist(t_re *re, t_coord *coord);
void				find_first_star(t_re *re, t_coord *coord);
void				find_direct_x_y(t_re *re, int dots, int me_en_x_y[4],
t_coord *coord);

#endif
