/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:40:59 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/13 15:29:09 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(t_list **lst)
{
	int	tmp;

	if (lst && *lst)
	{
		tmp = (*lst)->content;
		(*lst)->content = (*lst)->next->content;
		(*lst)->next->content = tmp;
	}
}

void	ft_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*first;
	t_list	*second;

	if (lst && *lst)
	{
		second = (*lst)->next;
		last = ft_lstlast(*lst);
		first = *lst;
		last->next = first;
		first->next = NULL;
		*lst = second;
	}
}

void	ft_reverse(t_list **lst)
{
	t_list	*node;
	t_list	*tmp;

	if (lst && *lst)
	{
		tmp = *lst;
		node = *lst;
		while (node)
		{
			if (node->next->next == NULL)
				break ;
			node = node->next;
		}
		*lst = ft_lstlast (*lst);
		(*lst)->next = tmp;
		node->next = NULL;
	}
}

void	ft_push(t_list **dest, t_list **src)
{
	t_list	*node;

	if (src && *src)
	{
		node = *dest;
		*dest = *src;
		*src = (*src)->next;
		(*dest)->next = node;
	}
}
