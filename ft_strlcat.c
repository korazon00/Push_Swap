/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:01:51 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/01 15:02:47 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ldest;
	size_t	lsrc;

	lsrc = ft_strlen(src);
	if (!dest && size == 0)
		return (lsrc);
	ldest = ft_strlen((const char *)dest);
	if (size <= ldest)
		return (lsrc + size);
	i = 0;
	while (src[i] && (ldest + i + 1) < size)
	{
		dest[ldest + i] = src[i];
		i++;
	}
	dest[ldest + i] = '\0';
	return (lsrc + ldest);
}
