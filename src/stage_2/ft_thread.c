/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:07:21 by knakto            #+#    #+#             */
/*   Updated: 2025/03/28 22:08:35 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include "pthread.h"

void	ft_mutex(t_mtx *m, t_mutex_mode mode)
{
	if (mode == MUTEX_INIT)
		if (pthread_mutex_init(m, NULL))
			clear("Error: Mutex initialization failed.");
	if (mode == MUTEX_LOCK)
		if (pthread_mutex_lock(m))
			clear("Error: ");
	if (mode == MUTEX_UNLOCK)
		if (pthread_mutex_unlock(m))
			clear("");
	if (mode == MUTEX_DESTROY)
		if (pthread_mutex_destroy(m))
			clear("");
}

void	ft_thread(t_philo *p, void *(*f)(void *), void *d, t_thread_mode mode)
{
	if (mode == THREAD_CREATE)
		if (pthread_create(&p->core, NULL, f, d))
			clear("");
	if (mode == THREAD_JOIN)
		if (pthread_join(p->core, NULL))
			clear("");
	if (mode == THREAD_DETACH)
		if (pthread_detach(p->core))
			clear("");
}
