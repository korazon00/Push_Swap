/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:19:31 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/08 16:25:28 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*biggest_node (t_list **lst)
{
	t_list	*node;
	t_list	*tmp;
	size_t	index;

	node = *lst;
	tmp = *lst;

	while (node)
	{
		if (node->content >= tmp->content)
		{
			tmp = node;
			index = tmp->index;
		}
		node = node->next;
	}
	return (tmp);
}

static void get_target (t_list **stack_a, t_list **stack_b)
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
			if (a->content > b->content && target == NULL)
			{
				i = b->content;
				target = b;
			}
			else if (a->content > b->content && i < b->content)
			{
				i = b->content;
				target = b;
			}
			b = b->next;
		}
		if (target == NULL)
			target = biggest_node (stack_b);
		a->target = target;
		a = a->next;
	}
}

static void ft_cost (t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	node = *stack_a;
	while (node)
	{
		if (node->index <= ft_lstsize (*stack_a) / 2)
			 node->cost = node->index;
		else
			 node->cost = (ft_lstsize (*stack_a) - node->index);
		if (node->target->index <= ft_lstsize (*stack_b) / 2)
			node->cost += node->target->index;
		else
			 node->cost += (ft_lstsize (*stack_b) - node->target->index);
		node = node->next;
	}
}

void	ft_sort_all (t_list **stack_a, t_list **stack_b)
{
	// t_list	*best;
	t_list *node = *stack_a;

	pb (stack_a, stack_b); 
	pb (stack_a, stack_b);
	while (ft_lstsize (*stack_a) > 3)
	{
		ft_index (stack_a);
		ft_index (stack_b);
		get_target (stack_a, stack_b);
		ft_cost (stack_a, stack_b);
		ft_push_the_best (stack_a, stack_b);
	}
	ft_sort_3 (stack_a);
	node = *stack_b;
	while (node)
	{
		ft_index (stack_b);
		ft_index (stack_a);
		ft_nega_target (stack_b, stack_a);
		ft_cost (stack_a, stack_b);
		ft_push_the_best (stack_a, stack_b);
		node = node->next;
	}
	

}