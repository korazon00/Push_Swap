/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:38:04 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/15 16:01:14 by faeljedd         ###   ########.fr       */
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

void	split_free(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free (split[i]);
		i++;
	}
	free (split);
}

void	free_str(t_list **stockage)
{
	t_list	*tmp;

	if (!*stockage)
		return ;
	while (*stockage)
	{
		tmp = (*stockage)->next;
		free ((*stockage)->str);
		free (*stockage);
		*stockage = tmp;
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
