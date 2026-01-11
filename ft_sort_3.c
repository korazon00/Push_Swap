/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:08:29 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/11 11:39:55 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_help(int a, int b, int c, t_list **lst)
{
	if (c > a && c > b)
	{
		if (a > b)
			sa (*lst);
	}
	if (a > b && a > c)
	{
		if (b > c)
		{
			sa (*lst);
			rra (lst);
		}
		else
			ra (lst);
	}
	if (b > a && b > c)
	{
		if (a < c)
		{
			sa (*lst);
			ra (lst);
		}
		else
			rra (lst);
	}
}

void	ft_sort_2(t_list **stack_a)
{
	if (!stack_a || !*stack_a)
		return ;
	if ((*stack_a)->content > (*stack_a)->next->content)
		ra (stack_a);
}

void	ft_sort_3(t_list **lst)
{
	int	a;
	int	b;
	int	c;

	a = (*lst)->content;
	b = (*lst)->next->content;
	c = (*lst)->next->next->content;
	ft_sort_help (a, b, c, lst);
}
