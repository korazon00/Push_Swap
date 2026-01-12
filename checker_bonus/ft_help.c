/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:53:00 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/12 22:02:41 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_valid(char *str)
{
	int	i;

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

void	ft_check(int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (split[0] == NULL)
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

int	ft_check_op(char *str)
{
	if (ft_strcmp(str, "sa\n" == 0))
		return (1);
	else if (ft_strcmp(str, "sb\n" == 0))
		return (1);
	else if (ft_strcmp(str, "ss\n" == 0))
		return (1);
	else if (ft_strcmp(str, "ra\n" == 0))
		return (1);
	else if (ft_strcmp(str, "rb\n" == 0))
		return (1);
	else if (ft_strcmp(str, "rr\n" == 0))
		return (1);
	else if (ft_strcmp(str, "rra\n" == 0))
		return (1);
	else if (ft_strcmp(str, "rrb\n" == 0))
		return (1);
	else if (ft_strcmp(str, "rrr\n" == 0))
		return (1);
	else if (ft_strcmp(str, "pa\n" == 0))
		return (1);
	else if (ft_strcmp(str, "pb\n" == 0))
		return (1);
	else
		return (0);
}

void	aply_op(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(str, "sa\n" == 0))
		ft_swap(&stack_a);
	else if (ft_strcmp(str, "sb\n" == 0))
		ft_swap(&stack_b);
	else if (ft_strcmp(str, "ss\n" == 0))
		ss(stack_a, stack_b);
	else if (ft_strcmp(str, "ra\n" == 0))
		ft_rotate(stack_a);
	else if (ft_strcmp(str, "rb\n" == 0))
		ft_rotate(stack_b);
	else if (ft_strcmp(str, "rr\n" == 0))
		rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rra\n" == 0))
		ft_reverse(stack_a);
	else if (ft_strcmp(str, "rrb\n" == 0))
		ft_reverse(stack_b);
	else if (ft_strcmp(str, "rrr\n" == 0))
		rrr(stack_a, stack_b);
	else if (ft_strcmp(str, "pa\n" == 0))
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n" == 0))
		ft_push(stack_b, stack_a);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}