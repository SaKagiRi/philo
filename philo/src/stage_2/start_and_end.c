/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_and_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:41:21 by knakto            #+#    #+#             */
/*   Updated: 2025/04/03 17:07:43 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	start(void)
{
	int		i;
	t_table	*t;

	i = 0;
	t = get_table();
	while (i < t->philo_nb)
	{
		ft_thread(&t->philo[i], simulator, &t->philo[i], THREAD_CREATE);
		i++;
	}
	if (t->philo_nb > 1)
		ft_thread(&t->philo[0], reaper, t, THREAD_CREATE);
}

void	end(void)
{
	int		i;
	t_table	*t;

	i = 0;
	t = get_table();
	while (i < t->philo_nb)
	{
		ft_thread(&t->philo[i], NULL, NULL, THREAD_JOIN);
		i++;
	}
}
