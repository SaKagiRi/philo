/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:54:54 by knakto            #+#    #+#             */
/*   Updated: 2025/03/25 23:54:28 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static bool	number_of_arg(int c, unsigned int min, unsigned int max)
{
	if (min > max || !c || !min || !max)
		return (false);
	if (c >= min && c <= max)
		return (true);
	return (false);
}

static bool	only_number(char **v)
{
	int	i;
	int	j;

	i = 1;
	while (v[i])
	{
		j = 0;
		while (v[i][j])
		{
			if (!(v[i][j] >= '0' && v[i][j] <= '9'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	range_int(char **v)
{
	int		i;
	long	number;

	i = 1;
	while (v[i])
	{
		number = atol(v[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (false);
		i++;
	}
	return (true);
}

static bool	util_setting(int c, char **v)
{
	int		number;
	int		i;

	i = 1;
	while (v[i])
	{
		number = atol(v[i]);
		if (i == 1 && !(number > 0 && number <= 200))
			return (false);
		else if (i >= 2 && i <= 4 && !(number >= 60))
			return (false);
		else if (i == 5 && !(number >= 0))
			return (false);
		i++;
	}
	return (true);
}

void	parser(int c, char **v)
{
	t_table	*t;

	t = get_table();
	if (!number_of_arg(c, 5, 6) || !only_number(v) || !range_int(v) \
		|| !util_setting(c, v))
		clear("Error: Invalid input.");
}
