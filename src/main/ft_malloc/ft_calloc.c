/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:15:41 by knakto            #+#    #+#             */
/*   Updated: 2025/03/25 23:15:54 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;
	size_t	i;

	if ((count >= SIZE_MAX && size >= SIZE_MAX)
		|| ((ssize_t)count && (ssize_t)size < 0)
		|| (ssize_t)count * (ssize_t)size < 0)
		return (NULL);
	i = count * size;
	alloc = malloc(i);
	if (alloc == NULL)
		return (NULL);
	while (i > 0)
	{
		*(char *)(alloc + (i - 1)) = '\0';
		i--;
	}
	return (alloc);
}
