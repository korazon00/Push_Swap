/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:20:41 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/11 17:59:54 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main (int argc, char **argv)
{
	t_list *stack_a;

	if (argc == 1)
		return (0);
	ft_check(argc, argv);
	stack_a = init_stack (argc, argv);

}