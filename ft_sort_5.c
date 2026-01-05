/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:28:47 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/05 23:14:21 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_index (t_list **lst)
{
	t_list *node;
	size_t i;

	i = 0;
	node = *lst;
	while (node)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}

static size_t ft_min_num (t_list **lst)
{
	t_list *node;
	t_list *tmp;
	size_t index;

	node = *lst;
	tmp = *lst;
	while (lst)
	{
		if (node->content < tmp->content)
		{
			tmp = node;
			index = tmp->index;
		}
		node = node->next;
	}
	return (index);
}

void	ft_sort_5(t_list **lst)
{
	size_t index;
	t_list *node;

	if (lst || *lst)
	{
		ft_index (lst);
		index = ft_min_num (lst);
		node = *lst;
		while (node->index != index)
		{
			if (index < 2)
				rra (lst);
			else
				sa (*lst);
			node = node->next;
		}
	}
}