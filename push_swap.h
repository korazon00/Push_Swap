/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 10:47:44 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/03 21:06:34 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct s_list
{
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
int is_valid (char *str);

void sa(t_list *lst);
void sb(t_list *lst);
void ss (t_list *lst1, t_list *lst2);
void ra (t_list **lst);
void rb (t_list **lst);
void rr (t_list **lst1, t_list **lst2);
void ra (t_list **lst);
void rb (t_list **lst);
void rrr (t_list **lst1, t_list lst2);



#endif