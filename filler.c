/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:20:31 by tshevchu          #+#    #+#             */
/*   Updated: 2017/07/12 18:54:42 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	record_let(t_re *re, char *line)
{
	if (ft_strnequ(line, "$$$ exec p1", 11))
	{
		re->l_me = 'o';
		re->l_en = 'x';
	}
	else
	{
		re->l_me = 'x';
		re->l_en = 'o';
	}
}

int		main(void)
{
	char	*line;
	t_re	*re;
	int		fd;

	line = NULL;
	fd = 0;
	re = create_empty_struct();
	get_next_line(fd, &line);
	record_let(re, line);
	ft_strdel(&line);
	while (get_next_line(fd, &line))
	{
		read_map(re, line, fd);
		ft_strdel(&line);
		find_direction(re);
		new_struct(re);
	}
	free(re);
	return (0);
}
