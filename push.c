/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:16:10 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/05 18:05:19 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_push (t_list **src, t_list **dest)
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

void pa(t_list **a, t_list **b)
{
	ft_push (b, a);
	write (1, "pa\n", 1);
}

void pb(t_list **a, t_list **b)
{
	ft_push (a, b);
	write (1, "pb\n", 1);
}
