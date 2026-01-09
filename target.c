/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:01:49 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/09 15:16:21 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_min_node (t_list **lst)
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

static t_list	*ft_nega_target_2 (t_list *a, t_list *b, t_list *target)
{
	int	i;

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
	return (target);
}

void	ft_nega_target (t_list **stack_a, t_list **stack_b)
{
	t_list *a;
	t_list *b;
	t_list *target;

	a = *stack_a;	
	while (a)
	{
		target = NULL;
		b = *stack_b;
		target = ft_nega_target_2 (a, b, target);
		if (target == NULL)
			target = ft_min_node (stack_b);
		a->target = target;
		a = a->next;
	}
}

void ft_finish (t_list **stack_a)
{
	t_list *node;

	ft_index (stack_a);
	node = ft_min_node(stack_a);
	while (node != *stack_a)
	{
		if (node->index <= (ft_lstsize (*stack_a) / 2))
			ra (stack_a);
		else
			rra (stack_a);
	}
}

void ft_pull_the_best (t_list **stack_a, t_list **stack_b)
{
	while ((*stack_b)->target != *stack_a)
	{
		if ((*stack_b)->target->index <= (ft_lstsize (*stack_a) / 2))
			ra (stack_a);
		else
			rra (stack_a);
	}
	pa (stack_a, stack_b);
}