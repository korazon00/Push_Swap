/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:14:22 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/12 18:15:46 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*ft_null(char const *s1, char const *s2)
{
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;	
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (ft_null (s1, s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc (s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	ft_strlcat (str, s2, s1_len + s2_len + 1);
	return (str);
}
