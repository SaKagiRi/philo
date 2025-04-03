/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:05:40 by knakto            #+#    #+#             */
/*   Updated: 2025/04/03 10:30:28 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	thinkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk(t_philo *p, t_table *t)
{
	time_t	think;

	ft_mutex(&t->meal_lock, MUTEX_LOCK);
	think = (p->time_to_die - (get_time() - p->last_meal)) / 2;
	ft_mutex(&t->meal_lock, MUTEX_UNLOCK);
	if (think > 600)
		think = 10;
	if (think < 0)
		think = 0;
	status(p, THINKING, t);
	if (p->eat != t->times_must_eat || t->times_must_eat == -1)
	{
		ft_sleep(think);
		return ;
	}
	ft_mutex(&t->must_eat_lock, MUTEX_LOCK);
	t->current_must_eat_times++;
	ft_mutex(&t->must_eat_lock, MUTEX_UNLOCK);
	while (check_must_eat(t))
		ft_sleep(100);
	ft_mutex(&t->stop_lock, MUTEX_LOCK);
	t->stop = true;
	ft_mutex(&t->stop_lock, MUTEX_UNLOCK);
}

static void	eat_sleep_routine(t_philo *p, t_table *t)
{
	lock_fork(p, t);
	status(p, EATING, t);
	ft_mutex(&t->meal_lock, MUTEX_LOCK);
	p->last_meal = get_time();
	ft_mutex(&t->meal_lock, MUTEX_UNLOCK);
	ft_sleep(p->time_to_eat);
	if (!is_stop())
	{
		ft_mutex(&t->meal_lock, MUTEX_LOCK);
		p->eat++;
		ft_mutex(&t->meal_lock, MUTEX_UNLOCK);
	}
	status(p, SLEEPING, t);
	ft_mutex(&t->fork[p->r_fork], MUTEX_UNLOCK);
	ft_mutex(&t->fork[p->l_fork], MUTEX_UNLOCK);
	ft_sleep(p->time_to_sleep);
	thinkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk(p, t);
}

static void	*only_one_philo(t_philo *p)
{
	t_table	*t;

	t = get_table();
	ft_mutex(&t->fork[p->l_fork], MUTEX_LOCK);
	status(p, TAKEFORK, t);
	ft_sleep(p->time_to_die);
	status(p, DIE, t);
	ft_mutex(&t->fork[p->l_fork], MUTEX_UNLOCK);
	return (NULL);
}

void	*simulator(void *data)
{
	t_philo	*p;
	t_table	*t;
	time_t	time;

	p = (t_philo *)data;
	ft_mutex(&p->type_lock, MUTEX_LOCK);
	t = get_table();
	ft_mutex(&p->type_lock, MUTEX_UNLOCK);
	if (t->times_must_eat == 0)
		return (NULL);
	p->last_meal = p->time_start;
	time = phild_philo(p, t);
	while (get_time() < p->time_start + time)
		usleep(100);
	if (t->philo_nb == 1)
		return (only_one_philo(p));
	while (!is_stop())
		eat_sleep_routine(p, t);
	return (NULL);
}
