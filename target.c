/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:01:49 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/08 16:15:18 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list *ft_min_num (t_list **lst)
{
	t_list *node;
	t_list *tmp;

	node = *lst;
	tmp = *lst;

	while (node)
	{
		if (node->content <= tmp->content)
		{
			tmp = node;
		}
		node = node->next;
	}
	return (tmp);
}

void	ft_nega_target (t_list **stack_a, t_list **stack_b)
{
	t_list *a;
	t_list *b;
	t_list *target;
	int i;

	a = *stack_a;	
	while (a)
	{
		target = NULL;
		b = *stack_b;
		while (b)
		{
			if (a->content < b->content && target == NULL)
			{
				i = b->content;
				target = b;
			}
			else if (a->content < b->content && i > b->content)
			{
				i = b->content;
				target = b;
			}
			b = b->next;
		}
		if (target == NULL)
			target = ft_min_num (stack_b);
		a->target = target;
		a = a->next;
	}
}