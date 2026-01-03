/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:24:33 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/03 21:05:47 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list * ft_swap_a (t_list *lst)
{
	int tmp;

	if (lst && lst->next)
	{
		tmp = lst->content;
		lst->content = lst->next->content;
		lst->next->content = tmp;
	}
	
	return (lst);
}

static t_list * ft_swap_b (t_list *lst)
{
	int tmp;

	if (lst && lst->next)
	{
		tmp = lst->content;
		lst->content = lst->next->content;
		lst->next->content = tmp;
	}
	return (lst);
}

void sa(t_list *lst)
{
	ft_swap_a(lst);
	write (1, "sa\n", 3);
}
void sb(t_list *lst)
{
	ft_swap_b(lst);
	write (1, "sb\n", 3);
}

void ss (t_list *lst1, t_list *lst2)
{
	ft_swap_a (lst1);
	ft_swap_b (lst2);
	write (1, "ss\n", 3);
}