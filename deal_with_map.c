/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:50:04 by tshevchu          #+#    #+#             */
/*   Updated: 2017/07/05 16:52:05 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_size_m(t_re *re, char *line, int i)
{
	if (re->m_x == 0)
	{
		re->m_x = ft_new_atoi(line, i);
		i = i + while_digits(re->m_x);
	}
	else
		re->m_y = ft_new_atoi(line, i);
	return (i);
}

void	record_map(t_re *re, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (re->m == NULL)
	{
		re->m = (char**)malloc(sizeof(char*) * (re->m_x + 1));
		re->m[re->m_x] = NULL;
	}
	get_next_line(fd, &line);
	ft_strdel(&line);
	while (i < re->m_x)
	{
		get_next_line(fd, &line);
		re->m[i] = ft_strsub(line, 4, (size_t)re->m_y);
		i++;
		ft_strdel(&line);
	}
	get_next_line(fd, &line);
	read_piece(re, fd, line);
}

void	read_map(t_re *re, char *line, int fd)
{
	int i;

	if (re->m_x == 0 && ft_strnequ(line, "Plateau", 7))
	{
		i = find_size_m(re, line, 8);
		find_size_m(re, line, i);
	}
	record_map(re, fd);
}
