/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:57:20 by knakto            #+#    #+#             */
/*   Updated: 2025/04/03 16:21:32 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*reaper(void *data)
{
	t_table	*t;
	int		i;

	t = (t_table *)data;
	while (!is_stop())
	{
		i = -1;
		while (++i < t->philo_nb)
		{
			status(&t->philo[i], CHECK_DIE, t);
			usleep(100);
		}
	}
	return (NULL);
}
