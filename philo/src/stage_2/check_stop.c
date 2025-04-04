/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:27:46 by knakto            #+#    #+#             */
/*   Updated: 2025/04/03 16:50:31 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	is_stop(void)
{
	t_table	*t;

	t = get_table();
	ft_mutex(&t->stop_lock, MUTEX_LOCK);
	if (t->stop)
	{
		ft_mutex(&t->stop_lock, MUTEX_UNLOCK);
		return (true);
	}
	ft_mutex(&t->stop_lock, MUTEX_UNLOCK);
	return (false);
}

bool	is_die(t_philo *p, t_table *t)
{
	ft_mutex(&t->meal_lock, MUTEX_LOCK);
	if (get_time() - p->last_meal > p->time_to_die)
	{
		ft_mutex(&t->meal_lock, MUTEX_UNLOCK);
		return (true);
	}
	ft_mutex(&t->meal_lock, MUTEX_UNLOCK);
	return (false);
}
