/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:56:25 by knakto            #+#    #+#             */
/*   Updated: 2025/03/26 02:36:03 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	init_philo(t_table *t)
{
	int		i;

	t->philo = ft_malloc(sizeof(t_philo), t->philo_nb);
	i = 0;
	while (i < t->philo_nb)
	{
		t->philo[i].time_start = t->time_start;
		t->philo[i].time_to_eat = t->time_to_eat;
		t->philo[i].time_to_sleep = t->time_to_sleep;
		t->philo[i].time_to_die = t->time_to_die;
		t->philo[i].l_fork = i;
		t->philo[i].r_fork = ((i + 1) % t->philo_nb);
		i++;
	}
}

static void	init_fork(t_table *t)
{
	int		i;

	i = 0;
	t->fork = ft_malloc(sizeof(t_mtx) ,t->philo_nb);
	while (i < t->philo_nb)
	{
		ft_mutex(&t->fork[i], MUTEX_INIT);
		i++;
	}
	ft_mutex(&t->stop_lock, MUTEX_INIT);
}

static void	init_value(t_table *t, int c, char **v)
{
	t->philo_nb = atol(v[1]);
	t->time_to_eat = atol(v[2]);
	t->time_to_sleep = atol(v[3]);
	t->time_to_die = atol(v[4]);
	t->times_must_eat = -1;
	if (c == 6)
		t->times_must_eat = atol(v[5]);
	t->stop = false;
	t->time_start = get_time();
}

void	print(t_table *t)
{
	int		i;
	t_philo	p;

	i = 0;
	while (i < t->philo_nb)
	{
		p = t->philo[i];
		printf("philo %d, l_fork %d, r_fork %d\n", i, p.l_fork, p.r_fork);
		printf("time to start = %ld\n", p.time_start);
		printf("time to eat = %ld\n", p.time_to_eat);
		printf("time to sleep = %ld\n", p.time_to_sleep);
		printf("time to die = %ld\n", p.time_to_die);
		i++;
	}
}

void	init(int c, char **v)
{
	t_table	*t;

	t = get_table();
	init_value(t, c, v);
	init_fork(t);
	init_philo(t);
	print(t);
}
