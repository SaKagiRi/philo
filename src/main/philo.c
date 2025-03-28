/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:48:33 by knakto            #+#    #+#             */
/*   Updated: 2025/03/29 00:21:43 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

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
