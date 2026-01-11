/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:01:51 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/11 18:21:31 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ldest;
	size_t	lsrc;

	lsrc = ft_strlen(src);
	if (!dest && size == 0)
		return (lsrc);
	ldest = ft_strlen((const char *)dest);
	if (size <= ldest)
		return (lsrc + size);
	i = 0;
	while (src[i] && (ldest + i + 1) < size)
	{
		dest[ldest + i] = src[i];
		i++;
	}
	dest[ldest + i] = '\0';
	return (lsrc + ldest);
}

void	ft_ultimate_cost_1(t_list *node)
{
	if (node->index >= node->target->index)
		node->cost = node->index;
	else
		node->cost = node->target->index;
}

void	ft_ultimate_cost_2(t_list **stack_a, t_list **stack_b, t_list *node)
{
	if ((ft_lstsize (*stack_a) - node->index)
		>= (ft_lstsize (*stack_b) - node->target->index))
		node->cost = (ft_lstsize (*stack_a) - node->index);
	else
		node->cost = (ft_lstsize (*stack_b) - node->target->index);
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

void	ft_free_exit(t_list **stack_a)
{
	t_list	*tmp;

	if (!stack_a && !*stack_a)
		return ;
	while (*stack_a)
	{
		tmp = *stack_a;
		free (*stack_a);
		*stack_a = tmp->next;
	}
	exit(1);
}
