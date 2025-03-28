/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:25:13 by knakto            #+#    #+#             */
/*   Updated: 2025/03/29 00:27:55 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	puterr(char *str)
{
	if (!str)
		return ;
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
}

void	clear(char	*msg)
{
	if (msg)
	{
		puterr(msg);
		ft_free();
	}
	else
		exit(0);
	exit(1);
}
