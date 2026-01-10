/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:20:26 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/10 16:22:31 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check (int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split (argv[i] , ' ');
		j = 0;
		while (split[j])
		{
			if (!(is_valid(split[j])))
				ft_error_exit();
			free (split[j]);
			j++;
		}
		free (split);
		i++;
	}
}

void	not_dup (t_list *lst, int content)		
{
	while (lst)
	{
		if (lst->content == content)
			ft_error_exit();
		else
			lst = lst->next;
	}
}
void	fill_stack (char *str, t_list **stack_a)
{
	char	**split;
	long	j;

	split = ft_split (str, ' ');
	if (split[0] == NULL)
		ft_error_exit ();
	j = 0;
	while (split[j])
	{
		not_dup (*stack_a, ft_atoi (split[j]));
		ft_lstadd_back (stack_a, ft_lstnew (ft_atoi (split[j])));
		
		//###free kolshi ###

		free (split[j]);
		j++;
	}
	free (split);
}

t_list	*init_stack (int argc, char **argv)
{
	t_list	*stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < argc )
	{
		fill_stack (argv[i], &stack_a);
		i++;
	}
	return (stack_a);
}

int	main (int argc, char **argv)
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
	if (argc == 2)
		return (0);
	else if (argc == 3)
		ft_sort_2 (&stack_a);
	else if (argc == 4)
		ft_sort_3 (&stack_a);
	else if (argc == 6 || argc == 5)
		ft_sort_5 (&stack_a, &stack_b);
	else
		ft_sort_all (&stack_a, &stack_b);
}
