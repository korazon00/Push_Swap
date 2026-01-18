/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:20:26 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/16 10:36:42 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check(int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL || split[0] == NULL)
			return (split_free(split), ft_error_exit());
		j = 0;
		while (split[j])
		{
			if (!(is_valid(split[j])))
			{
				free (split[j]);
				free (split);
				ft_error_exit();
			}
			free (split[j]);
			j++;
		}
		free (split);
		i++;
	}
}

void	not_dup(t_list **lst, int content, char **split, t_list **new_node)
{
	t_list	*node;

	node = *lst;
	while (node)
	{
		if (node->content == content)
		{
			free (*new_node);
			split_free(split);
			ft_free_lst(lst);
			ft_error_exit();
		}
		else
			node = node->next;
	}
}

void	fill_stack(char *str, t_list **stack_a)
{
	char	**split;
	long	j;
	t_list	*content;

	split = ft_split(str, ' ');
	if (split == NULL)
		ft_error_exit ();
	j = 0;
	while (split[j])
	{
		content = ft_lstnew(ft_atoi (split[j]));
		if (!content)
		{
			split_free(split);
			ft_free_exit(stack_a);
		}
		not_dup (stack_a, ft_atoi (split[j]), split, &content);
		ft_lstadd_back (stack_a, content);
		free (split[j]);
		j++;
	}
	free (split);
}

t_list	*init_stack(int argc, char **argv)
{
	t_list	*stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		fill_stack (argv[i], &stack_a);
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	ft_check(argc, argv);
	stack_a = init_stack (argc, argv);
	if ((ft_sorted_lst (&stack_a)))
		return (ft_free_lst (&stack_a), 0);
	if (ft_lstsize (stack_a) == 1)
		return (ft_free_lst (&stack_a), 0);
	else if (ft_lstsize (stack_a) == 2)
		ft_sort_2 (&stack_a);
	else if (ft_lstsize (stack_a) == 3)
		ft_sort_3 (&stack_a);
	else if (ft_lstsize (stack_a) == 4 || ft_lstsize (stack_a) == 5)
		ft_sort_5 (&stack_a, &stack_b);
	else
		ft_sort_all (&stack_a, &stack_b);
	ft_free_lst (&stack_a);
}
