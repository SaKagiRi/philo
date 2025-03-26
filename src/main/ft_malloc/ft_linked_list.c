/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:09:14 by knakto            #+#    #+#             */
/*   Updated: 2025/03/25 23:12:26 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	node = *lst;
	while (node -> next != NULL)
		node = node -> next;
	node -> next = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst -> content);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
