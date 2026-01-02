/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 10:47:32 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/01 10:49:26 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	in_word;

	in_word = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*ft_malloc_word(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	word = malloc ((end - start) + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word [i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	free_all(char **arr, size_t j)
{
	while (j >= 0)
		free (arr[j--]);
	free (arr);
}

static size_t	fil_arr(const char *s, char c, char **arr)
{
	size_t	i;
	size_t	j;
	size_t	start;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		arr[j] = ft_malloc_word(s, start, i);
		if (!arr[j])
		{
			free_all (arr, j - 1);
			return (0);
		}
		j++;
	}
	arr[count_words(s, c)] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (s == NULL)
		return (NULL);
	arr = malloc((count_words(s, c) + 1) * (sizeof(char *)));
	if (!arr)
		return (NULL);
	if (!(fil_arr(s, c, arr)))
		return (NULL);
	return (arr);
}
