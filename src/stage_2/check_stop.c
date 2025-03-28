/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:27:46 by knakto            #+#    #+#             */
/*   Updated: 2025/03/29 00:23:45 by knakto           ###   ########.fr       */
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
