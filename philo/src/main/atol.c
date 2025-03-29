/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:46:28 by knakto            #+#    #+#             */
/*   Updated: 2025/03/25 21:47:10 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	space(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

long	ft_htol(const char *nptr)
{
	size_t		i;
	int			j;
	char		*hex;
	long		res;

	i = 0;
	res = 0;
	hex = "0123456789ABCDEF";
	while (space(*(nptr + i)) == 1)
		i++;
	while (nptr[i])
	{
		j = 0;
		while (j <= 15 && nptr[i] != hex[j])
			j++;
		if (j <= 15)
			res = res * 16 + j;
		else
			break ;
		i++;
	}
	return (res);
}
