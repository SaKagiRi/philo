/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simutator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:05:40 by knakto            #+#    #+#             */
/*   Updated: 2025/03/26 03:06:54 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	thinkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk(t_philo *p)
{
	t_table	*t;
	time_t	think;

	t = get_table();
	ft_mutex(&t->meal_lock, MUTEX_LOCK);
	think = (p->time_to_die - (get_time() - p->last_meal - p->time_to_eat)) / 2;
	ft_mutex(&t->meal_lock, MUTEX_UNLOCK);
	if (think < 0)
		think = 0;
	printf("THINK\n");
	ft_sleep(think);
}

static void	eat_sleep_routine(t_philo *p)
{
	t_table	*t;

	t = get_table();
	ft_mutex(&t->fork[p->l_fork], MUTEX_LOCK);
	printf("GET_FORK_L\n");
	ft_mutex(&t->fork[p->r_fork], MUTEX_LOCK);
	printf("GET_FORK_R\n");
	ft_mutex(&t->meal_lock, MUTEX_LOCK);
	p->last_meal = get_time();
	ft_mutex(&t->meal_lock, MUTEX_UNLOCK);
	ft_sleep(p->time_to_sleep);
	if (!is_stop())
	{
		ft_mutex(&t->meal_lock, MUTEX_LOCK);
		p->eat++;
		ft_mutex(&t->meal_lock, MUTEX_UNLOCK);
	}
	printf("SLEEP\n");
	ft_mutex(&t->fork[p->l_fork], MUTEX_UNLOCK);
	ft_mutex(&t->fork[p->r_fork], MUTEX_UNLOCK);
	ft_sleep(p->time_to_sleep);
	thinkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk(p);
}

static void	*only_one_philo(t_philo *p)
{
	t_table	*t;

	t = get_table();
	ft_mutex(&t->fork[p->l_fork], MUTEX_LOCK);
	printf("GET_FORK_L\n");
	ft_sleep(p->time_to_die);
	printf("DIED");
	ft_mutex(&t->fork[p->l_fork], MUTEX_UNLOCK);
	return (NULL);
}

void	*simulator(void *data)
{
	t_philo	*p;
	t_table	*t;

	t = get_table();
	if (t->times_must_eat == 0)
		return (NULL);
	p = (t_philo *)data;
	p->last_meal = p->time_start;
	while (get_time() < p->time_start)
		usleep(100);
	if (t->philo_nb == 1)
		return(only_one_philo(p));
	while (!is_stop())
		eat_sleep_routine(p);
	return (NULL);
}
