/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:44:41 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/13 15:28:37 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*ft_lstnew(char *str)
{
	t_list	*node;

	node = malloc (sizeof(t_list));
	if (!node)
		return (NULL);
	node ->str = str;
	node ->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (lst == NULL)
		return (NULL);
	last = lst;
	while (last != NULL)
	{
		if (last->next == NULL)
			return (last);
		last = last->next;
	}
	return (last);
}

size_t	ft_lstsize(t_list *lst)
{
	size_t		size;
	t_list		*node;

	node = lst;
	size = 0;
	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return (size);
}

t_list	*ft_lstnew_2(int content)
{
	t_list	*node;

	node = malloc (sizeof(t_list));
	if (!node)
		return (NULL);
	node ->content = content;
	node ->next = NULL;
	return (node);
}
