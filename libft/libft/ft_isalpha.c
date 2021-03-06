/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:17:50 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 15:51:31 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	unsigned char s;

	s = (unsigned char)c;
	if (c < 0 || c > 255)
		return (0);
	if ((s >= 65 && s <= 90) || (s >= 97 && s <= 122))
		return (1);
	return (0);
}
