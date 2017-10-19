/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:48:50 by tshevchu          #+#    #+#             */
/*   Updated: 2017/07/05 18:18:41 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

int		ft_new_atoi(char *str, int i)
{
	int result;
	int f;

	result = 0;
	f = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45)
		f = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * f);
}

int		while_digits(int nb)
{
	int i;

	i = 1;
	while (nb >= 10)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}
