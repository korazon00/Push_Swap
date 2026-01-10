/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:07:11 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/10 12:29:05 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int is_valid (char *str)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0' || str[i] == 9)
			return (0);
		i++;
	}
	return (1);
}

t_list	*ft_best_cost (t_list **stack_a)
{
	t_list	*node;
	t_list	*best;
	size_t	tmp;

	tmp = 2147483647;
	node = *stack_a;
	while (node)
	{
		if (node->cost < tmp)
		{
			tmp = node->cost;
			best = node;
		}
		node = node->next;
	}
	return (best);
}

void	ft_push_the_best (t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	t_list	*best;

	node = *stack_a;
	best = ft_best_cost (stack_a);
	while (best != *stack_a)
	{
		if(best != *stack_a)
		{
			if (best->index <= (ft_lstsize (*stack_a) / 2))
			{
				if ((best->target->index <= (ft_lstsize (*stack_b) / 2)) && (best->target != *stack_b))
					rr (stack_a, stack_b);
				else
					ra (stack_a);
			}
			else
			{
				if ((best->target->index > (ft_lstsize (*stack_b)) / 2) && (best->target != *stack_b))
					rrr (stack_a, stack_b);
				else
					rra (stack_a);
			}
		}
	}
	while (best->target != *stack_b)
	{
		if (best->target != *stack_b)
		{
			if (best->target->index <= (ft_lstsize (*stack_b) / 2))
				rb (stack_b);
			else
				rrb (stack_b);
		}
	}
	pb (stack_a, stack_b);
}
