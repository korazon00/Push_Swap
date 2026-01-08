/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 10:47:44 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/08 16:24:53 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct s_list
{
	size_t			cost;
	struct s_list	*target;
	size_t			index;
	int				content;
	struct s_list	*next;
}					t_list;



char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void ft_error_exit (void);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
size_t	ft_lstsize(t_list *lst);
int is_valid (char *str);

void sa(t_list *lst);
void sb(t_list *lst);
void ss (t_list *lst1, t_list *lst2);
void ra (t_list **lst);
void rb (t_list **lst);
void rr (t_list **lst1, t_list **lst2);
void ra (t_list **lst);
void rb (t_list **lst);

void rra (t_list **lst);
void rrb (t_list **lst);
void rrr(t_list **lst1, t_list **lst2);
void pa(t_list **a, t_list **b);
void pb(t_list **b, t_list **a);

void ft_index (t_list **lst);
t_list *ft_best_cost (t_list **stack_a);
void ft_push_the_best (t_list **stack_a, t_list **stack_b);
t_list	*biggest_node (t_list **lst);

void	ft_sort_3 (t_list **lst);
void	ft_sort_5 (t_list **stack_a, t_list **stack_b);
void	ft_sort_all (t_list **stack_a, t_list **stack_b);

void	ft_nega_target (t_list **stack_a, t_list **stack_b);


#endif