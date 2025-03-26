/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:27:46 by knakto            #+#    #+#             */
/*   Updated: 2025/03/26 02:38:59 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	is_stop(void)
{
	t_table	*t;
	bool	status;

	t = get_table();
	ft_mutex(&t->stop_lock, MUTEX_LOCK);
	status = t->stop;
	ft_mutex(&t->stop_lock, MUTEX_UNLOCK);
	return (status);
}
