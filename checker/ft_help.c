/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:53:00 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/11 18:40:01 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check(int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
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

void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit (1);
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