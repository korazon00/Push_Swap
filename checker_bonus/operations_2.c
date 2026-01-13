/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:47:54 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/13 15:28:54 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_list **lst1, t_list **lst2)
{
	ft_reverse(lst1);
	ft_reverse(lst2);
}

void	rr(t_list **lst1, t_list **lst2)
{
	ft_rotate(lst1);
	ft_rotate(lst2);
}

void	ss(t_list *lst1, t_list *lst2)
{
	ft_swap(&lst1);
	ft_swap(&lst2);
}
