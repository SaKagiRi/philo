/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:19:38 by knakto            #+#    #+#             */
/*   Updated: 2025/03/29 00:14:01 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	lock_fork(t_philo *p, t_table *t)
{
	if (p->nb == t->philo_nb)
	{
		ft_mutex(&t->fork[p->r_fork], MUTEX_LOCK);
		status(p, TAKEFORK, t);
		ft_mutex(&t->fork[p->l_fork], MUTEX_LOCK);
		status(p, TAKEFORK, t);
		return ;
	}
	ft_mutex(&t->fork[p->l_fork], MUTEX_LOCK);
	status(p, TAKEFORK, t);
	ft_mutex(&t->fork[p->r_fork], MUTEX_LOCK);
	status(p, TAKEFORK, t);
	return ;
}

time_t	phild_philo(t_philo *p, t_table *t)
{
	time_t	time;

	time = 0;
	if (t->philo_nb == 1)
		return (time);
	else if (t->philo_nb % 2 == 0)
		time = (t->time_to_die - t->time_to_eat) / 2;
	else if (t->philo_nb % 2 != 0)
		time = (p->nb % 3) * ((t->time_to_die - t->time_to_eat) / 3);
	return (time);
}
