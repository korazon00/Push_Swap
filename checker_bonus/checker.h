/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:07:58 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/13 15:26:41 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	char			*str;
	int				content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	aply_op(char *str, t_list **stack_a, t_list **stack_b);

char	**ft_split(char const *s, char c);
t_list	*init_stack(int argc, char **argv);
void	ft_error_exit(void);
int		is_valid(char *str);
void	ft_check(int argc, char **argv);
void	ft_check(int argc, char **argv);
void	split_free(char **split);
void	ft_free_exit(t_list **stack_a);
void	ft_free_lst(t_list **stack_a);
t_list	*ft_lstnew(char *str);
t_list	*ft_lstnew_2(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_lstsize(t_list *lst);
void	ft_read_input(t_list **stack_a);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_check_op(char *str);
void	ft_swap(t_list **lst);
void	ft_rotate(t_list **lst);
void	ft_reverse(t_list **lst);
void	rrr(t_list **lst1, t_list **lst2);
void	rr(t_list **lst1, t_list **lst2);
void	ss(t_list *lst1, t_list *lst2);
void	ft_push(t_list **dest, t_list **src);
int		ft_sorted_lst(t_list **stack_a);
void	fill_stack(char *str, t_list **stack_a);
int		ft_atoi(const char *str);
void	not_dup(t_list **lst, int content, char **split, t_list **new_node);
void	check_and_add(char *str, t_list **stockage, t_list **stack_a);
void	free_str(t_list **stockage);

#endif