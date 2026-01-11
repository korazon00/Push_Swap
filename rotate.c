/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:47:32 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/11 13:11:21 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_a(t_list **lst)
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

static void	ft_rotate_b(t_list **lst)
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

void	ra(t_list **lst)
{
	ft_rotate_a (lst);
	write (1, "ra\n", 3);
}

void	rb(t_list **lst)
{
	ft_rotate_b (lst);
	write (1, "rb\n", 3);
}

void	rr(t_list **lst1, t_list **lst2)
{
	ft_rotate_a (lst1);
	ft_rotate_b (lst2);
	write (1, "rr\n", 3);
}
