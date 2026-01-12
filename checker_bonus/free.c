/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:38:04 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/12 15:40:54 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_free_lst(t_list **stack_a)
{
	t_list	*tmp;

	if (!*stack_a)
		return ;
	while (*stack_a)
	{
		tmp = (*stack_a)->next;
		free (*stack_a);
		*stack_a = tmp;
	}
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

void	split_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free (split[i]);
		i++;
	}
	free (split);
}

