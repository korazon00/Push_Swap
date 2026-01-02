/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:20:26 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/02 18:36:00 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int is_valid (char *str)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0' || str[i] == 9)
			return (0);
		i++;
	}
	return (1);
}

void ft_check (int argc, char **argv)
{
	int i;
	int j;
	char **split;

	i = 1;
	while (i < argc)
	{
		split = ft_split (argv[i] , ' ');
		j = 0;
		while (split[j])
		{
			if (!(is_valid(split[j])))
				ft_error_exit();
			j++;
		}
		i++;
	}
	// return (split);
}

void not_dup (t_list *lst, int content)		
{
	while (lst)
	{
		if (lst->content == content)
			ft_error_exit();
		else
			lst = lst->next;
	}
}

int main (int argc, char **argv)
{
	int i;
	int j;
	char **split;
	t_list *stack_a;
	int content;

	i = 1;
	if (argc == 1)
		return (0);
	ft_check(argc, argv);
	while (argv[i])
	{
		split = ft_split (argv[i], ' ');
		j = 0;
		while (split[j])
		{
			content = ft_atoi (split[j]);
			if (i == 0)
				stack_a = ft_lstnew (content);
			else
			{
				not_dup (stack_a, content);
				ft_lstadd_back (&stack_a, ft_lstnew (content));
			}
			j++;
		}
		i++;
	}
			while (stack_a)
			{
			printf ("%d\n", stack_a->content);
			stack_a = stack_a->next;
			}
			write (1, "success\n", 7);
}
