/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:16:10 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/13 10:02:14 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_list **dest, t_list **src)
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

void	pa(t_list **a, t_list **b)
{
	ft_push(a, b);
	write (1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	ft_push(b, a);
	write (1, "pb\n", 3);
}
