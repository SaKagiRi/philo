/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:50:13 by knakto            #+#    #+#             */
/*   Updated: 2025/03/26 02:49:13 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include "unistd.h"

time_t	get_time(void)
{
	struct timeval t;
	if (gettimeofday(&t, NULL) == -1)
		clear("Error: Gettime failed.");
	return ((t.tv_sec * 1e3) + (t.tv_usec / 1e3));
}

void	ft_sleep(time_t time)
{
	time += get_time();
	while (get_time() < time && !is_stop())
		usleep(100);
}

