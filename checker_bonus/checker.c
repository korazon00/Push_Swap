/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:20:41 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/12 22:44:10 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stockage;
	char	*str;

	if (argc == 1)
		return (0);
	ft_check(argc, argv);
	stack_a = init_stack (argc, argv);
	if (ft_lstsize (stack_a) == 1)
		write (1, "0K\n", 3);
	str = get_next_line(0);
	stockage = ft_lstnew(str);
	while (str)
	{
		free (str);
		if (!ft_check_op(stockage->str))
			ft_error_exit();
		str = get_next_line(0);
		ft_lstadd_back (&stockage, ft_lstnew(str));
	}
	while (stockage)
	{
		aply_op(stockage->str, &stack_a, &stack_b);
		stockage = stockage->next;
	}
	if (ft_sorted_lst(&stack_a) && stack_b == NULL)
		write (1, "0K\n", 3);
	else
		write (1, "KO\n", 3);
}
