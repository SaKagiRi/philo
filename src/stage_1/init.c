/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:56:25 by knakto            #+#    #+#             */
/*   Updated: 2025/03/29 00:41:13 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	init_philo(t_table *t)
{
	int		i;
	t_mtx	l_t;

	ft_mutex(&l_t, MUTEX_INIT);
	t->philo = ft_malloc(sizeof(t_philo), t->philo_nb);
	i = 0;
	while (i < t->philo_nb)
	{
		t->philo[i].nb = i + 1;
		t->philo[i].time_start = t->time_start;
		t->philo[i].time_to_eat = t->time_to_eat;
		t->philo[i].time_to_sleep = t->time_to_sleep;
		t->philo[i].time_to_die = t->time_to_die;
		t->philo[i].l_fork = i;
		t->philo[i].r_fork = ((i + 1) % t->philo_nb);
		t->philo[i].type_lock = l_t;
		i++;
	}
}

static void	init_fork(t_table *t)
{
	int		i;

	i = 0;
	t->fork = ft_malloc(sizeof(t_mtx), t->philo_nb);
	while (i < t->philo_nb)
	{
		ft_mutex(&t->fork[i], MUTEX_INIT);
		i++;
	}
	ft_mutex(&t->stop_lock, MUTEX_INIT);
	ft_mutex(&t->must_eat_lock, MUTEX_INIT);
}

static void	init_value(t_table *t, int c, char **v)
{
	t->philo_nb = atol(v[1]);
	t->time_to_die = atol(v[2]);
	t->time_to_eat = atol(v[3]);
	t->time_to_sleep = atol(v[4]);
	t->times_must_eat = -1;
	if (c == 6)
		t->times_must_eat = atol(v[5]);
	t->stop = false;
	t->current_must_eat_times = 0;
	t->time_start = get_time() + (t->philo_nb * 30);
}

static void	init_time_control(t_table *t)
{
	if (t->philo_nb % 2 == 0)
		t->time_control = 2;
	else if (t->philo_nb % 2 != 0)
		t->time_control = 3;
}

void	init(int c, char **v)
{
	t_table	*t;

	t = get_table();
	init_value(t, c, v);
	init_fork(t);
	init_philo(t);
	init_time_control(t);
}
