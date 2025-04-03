/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:48:33 by knakto            #+#    #+#             */
/*   Updated: 2025/04/03 17:09:20 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

#if DEBUG == 1

void	debug_table(void)
{
	int		i;
	t_table	*t;

	i = 0;
	t = get_table();
	printf("t_table pointer: %p\n", (void *)t);
	printf("t->philo pointer: %p\n", (void *)t->philo);
	printf("t->fork pointer: %p\n", (void *)t->fork);
	printf("t->stop_lock: %p\n", (void *)&t->stop_lock);
	printf("t->meal_lock: %p\n", (void *)&t->meal_lock);
	printf("t->must_eat_lock: %p\n", (void *)&t->must_eat_lock);
	while (i < t->philo_nb)
	{
		printf("\nPhilo[%d] pointer: %p\n", i, (void *)&t->philo[i]);
		printf("  core (pthread_t): %p\n", (void *)&t->philo[i].core);
		printf("  type_lock: %p\n", (void *)&t->philo[i].type_lock);
		printf("  Left fork index: %d (Address: %p)\n", t->philo[i].l_fork,
			(void *)&t->fork[t->philo[i].l_fork]);
		printf("  Right fork index: %d (Address: %p)\n", t->philo[i].r_fork,
			(void *)&t->fork[t->philo[i].r_fork]);
		i++;
	}
}

int	main(int c, char **v)
{
	if (c > 6 || c < 5)
		clear(HELP_MSG);
	parser(c, v);
	init(c, v);
	debug_table();
	start();
	end();
	ft_free();
}

#else

int	main(int c, char **v)
{
	if (c > 6 || c < 5)
		clear(HELP_MSG);
	parser(c, v);
	init(c, v);
	start();
	end();
	ft_free();
}

#endif
