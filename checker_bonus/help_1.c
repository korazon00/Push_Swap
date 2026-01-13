/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:35:36 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/13 15:29:39 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_sorted_lst(t_list **stack_a)
{
	t_list	*node;

	if (!*stack_a)
		return (1);
	node = *stack_a;
	while (node->next)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
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
		content = ft_lstnew_2(ft_atoi (split[j]));
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

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	int		i;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if ((result * sign > 2147483647) || (result * sign < -2147483648))
			ft_error_exit();
		i++;
	}
	return (result * sign);
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
