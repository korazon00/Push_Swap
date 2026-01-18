/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:17:09 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/15 16:26:25 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse(t_list **lst)
{
	t_list	*node;
	t_list	*tmp;

	if (lst && *lst && (*lst)->next)
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

void	rra(t_list **lst)
{
	ft_reverse(lst);
	write (1, "rra\n", 4);
}

void	rrb(t_list **lst)
{
	ft_reverse(lst);
	write (1, "rrb\n", 4);
}

void	rrr(t_list **lst1, t_list **lst2)
{
	ft_reverse(lst1);
	ft_reverse(lst2);
	write (1, "rrr\n", 4);
}
