/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:28:47 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/11 12:55:04 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_list **lst)
{
	t_list	*node;
	size_t	i;

	i = 0;
	node = *lst;
	while (node)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}

static size_t	ft_min_num(t_list **lst)
{
	t_list	*node;
	t_list	*tmp;
	size_t	index;

	node = *lst;
	tmp = *lst;
	while (node)
	{
		if (node->content <= tmp->content)
		{
			tmp = node;
			index = tmp->index;
		}
		node = node->next;
	}
	return (index);
}

static void	ft_push_min(t_list **stack_a, t_list **stack_b, size_t index)
{
	t_list	*node;

	node = *stack_a;
	while (node)
	{
		if (node->index == index)
		{
			while ((*stack_a)->index != index)
			{
				if (index <= (ft_lstsize(*stack_a) / 2))
					ra (stack_a);
				else
					rra (stack_a);
			}
			if ((*stack_a)->index == index)
			{
				pb (stack_a, stack_b);
				return ;
			}
		}
		node = node->next;
	}
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	size_t	index;

	if (stack_a && *stack_a)
	{
		if (ft_lstsize (*stack_a) == 5)
		{
			ft_index (stack_a);
			index = ft_min_num (stack_a);
			ft_push_min (stack_a, stack_b, index);
			ft_index (stack_a);
			index = ft_min_num (stack_a);
			ft_push_min (stack_a, stack_b, index);
			ft_sort_3 (stack_a);
			pa (stack_a, stack_b);
			pa (stack_a, stack_b);
		}
		else
		{
			ft_index (stack_a);
			index = ft_min_num (stack_a);
			ft_push_min (stack_a, stack_b, index);
			ft_sort_3 (stack_a);
			pa (stack_a, stack_b);
		}
	}
}
