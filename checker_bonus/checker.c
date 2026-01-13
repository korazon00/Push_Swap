/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:20:41 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/13 15:30:21 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_and_add(char *str, t_list **stockage, t_list **stack_a)
{
	*stockage = ft_lstnew(str);
	if (!*stockage)
	{
		free (str);
		str = NULL;
		ft_free_lst(stack_a);
		exit (1);
	}
	while (str)
	{
		if (!ft_check_op(str))
		{
			free_str (stockage);
			ft_free_lst(stack_a);
			ft_error_exit();
		}
		str = get_next_line(0);
		ft_lstadd_back (stockage, ft_lstnew(str));
	}
}

void	ft_finish(t_list **stack_a, t_list **stack_b)
{
	if (ft_sorted_lst(stack_a) && *stack_b == NULL)
	{
		ft_free_lst(stack_a);
		write (1, "0K\n", 3);
	}
	else
	{
		ft_free_lst(stack_a);
		ft_free_lst(stack_b);
		write (1, "KO\n", 3);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stockage;
	t_list	*tmp;
	char	*str;

	if (argc == 1)
		return (0);
	ft_check(argc, argv);
	stack_a = init_stack(argc, argv);
	str = get_next_line(0);
	check_and_add(str, &stockage, &stack_a);
	tmp = stockage;
	while (stockage)
	{
		aply_op(stockage->str, &stack_a, &stack_b);
		stockage = stockage->next;
	}
	free_str (&tmp);
	ft_finish(&stack_a, &stack_b);
}
