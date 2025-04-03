/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:52:29 by knakto            #+#    #+#             */
/*   Updated: 2025/04/03 17:08:58 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	status(t_philo *p, t_status input_status, t_table *t)
{
	time_t	current_time;

	current_time = get_time() - p->time_start;
	if (is_stop())
		return ;
	if ((input_status == CHECK_DIE && is_die(p, t)) || input_status == DIE)
	{
		ft_mutex(&t->stop_lock, MUTEX_LOCK);
		t->stop = true;
		ft_mutex(&t->stop_lock, MUTEX_UNLOCK);
		printf("%ld %d died\n", current_time - 1, p->nb);
	}
	else if (input_status == EATING)
		printf("%ld %d is eating\n", current_time, p->nb);
	else if (input_status == SLEEPING)
		printf("%ld %d is sleeping\n", current_time, p->nb);
	else if (input_status == THINKING)
		printf("%ld %d is thinking\n", current_time, p->nb);
	else if (input_status == TAKEFORK)
		printf("%ld %d has taken a fork\n", current_time, p->nb);
}
