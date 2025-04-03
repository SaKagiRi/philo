/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 04:24:52 by knakto            #+#    #+#             */
/*   Updated: 2025/04/03 16:46:52 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include "../src/main/ft_malloc/ft_malloc.h"

# define HELP_MSG		"Usage:\n	./philo <number_of_philosophers> <time_to_die\
time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]"

typedef pthread_mutex_t	t_mtx;

typedef struct s_philo
{
	int				nb;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			time_start;
	pthread_t		core;
	char			status;
	time_t			last_meal;
	int				l_fork;
	int				r_fork;
	int				eat;
	t_mtx			type_lock;
}	t_philo;

typedef struct s_table
{
	t_philo		*philo;
	int			current_must_eat_times;
	int			time_control;
	int			philo_nb;
	int			times_must_eat;
	time_t		time_start;
	time_t		time_to_die;
	time_t		time_to_eat;
	time_t		time_to_sleep;
	bool		stop;
	t_mtx		stop_lock;
	t_mtx		meal_lock;
	t_mtx		must_eat_lock;
	t_mtx		*fork;
}	t_table;

typedef enum e_time_mode
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}	t_time_mode;

typedef enum e_status
{
	ALIVE,
	DIE,
	EATING,
	SLEEPING,
	THINKING,
	TAKEFORK,
	CHECK_DIE,
}	t_status;

typedef enum e_mutex_mode
{
	MUTEX_INIT,
	MUTEX_LOCK,
	MUTEX_UNLOCK,
	MUTEX_DESTROY,
}	t_mutex_mode;

typedef enum e_thread_mode
{
	THREAD_CREATE,
	THREAD_JOIN,
	THREAD_DETACH,
}	t_thread_mode;

t_table	*get_table(void);
void	clear(char *smg);
void	parser(int c, char **v);
long	ft_htol(const char *nptr);
void	init(int c, char **v);
time_t	get_time(void);
void	ft_thread(t_philo *p, void *(*f)(void *), void *d, t_thread_mode mode);
void	ft_mutex(t_mtx *m, t_mutex_mode mode);
bool	is_stop(void);
void	ft_sleep(time_t time);
void	*simulator(void *data);
void	start(void);
void	end(void);
void	status(t_philo *p, t_status input_status, t_table *t);
void	lock_fork(t_philo *p, t_table *t);
time_t	phild_philo(t_philo *p, t_table *t);
bool	check_must_eat(t_table *t);
void	*reaper(void *data);
bool	is_die(t_philo *p, t_table *t);

#endif
