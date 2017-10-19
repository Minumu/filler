/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:53:48 by tshevchu          #+#    #+#             */
/*   Updated: 2017/07/05 16:55:27 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_size_p(t_re *re, char *line, int i)
{
	if (re->p_x == 0)
	{
		re->p_x = ft_new_atoi(line, i);
		i = i + while_digits(re->p_x);
	}
	else
		re->p_y = ft_new_atoi(line, i);
	return (i);
}

void	record_piece(t_re *re, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (re->p == NULL)
	{
		re->p = (char**)malloc(sizeof(char*) * (re->p_x + 1));
		re->p[re->p_x] = NULL;
	}
	while (i < re->p_x)
	{
		get_next_line(fd, &line);
		re->p[i] = ft_strdup(line);
		i++;
		ft_strdel(&line);
	}
}

void	read_piece(t_re *re, int fd, char *line)
{
	int i;

	i = 0;
	if (re->p_x == 0 && ft_strnequ(line, "Piece", 5))
	{
		i = find_size_p(re, line, 6);
		find_size_p(re, line, i);
	}
	ft_strdel(&line);
	record_piece(re, fd);
}
