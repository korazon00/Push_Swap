/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:35:36 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/12 22:07:13 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*ft_swap(t_list **lst)
{
	int	tmp;

	if (lst && (*lst)->next)
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

	if (lst && (*lst)->next)
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

	if (lst && (*lst)->next)
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

void	rrr(t_list **lst1, t_list **lst2)
{
	ft_reverse(lst1);
	ft_reverse(lst2);
}

void	rr(t_list **lst1, t_list **lst2)
{
	ft_rotate(lst1);
	ft_rotate(lst2);
}

void	ss(t_list *lst1, t_list *lst2)
{
	ft_swap(lst1);
	ft_swap(lst2);
}

void	ft_push(t_list **dest, t_list **src)
{
	t_list	*node;

	if (src || *src)
	{
		node = *dest;
		*dest = *src;
		*src = (*src)->next;
		(*dest)->next = node;
	}
}

int	ft_sorted_lst(t_list **stack_a)
{
	t_list	*node;

	if (!*stack_a)
		return (1);
	node = *stack_a;
	while (node->next)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}