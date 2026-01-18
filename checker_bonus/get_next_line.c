/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faeljedd <faeljedd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:15:15 by faeljedd          #+#    #+#             */
/*   Updated: 2026/01/16 10:37:21 by faeljedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*fill_line_buffer(int fd, char *stockage)
{
	char	*buffer;
	char	*temp;
	int		x;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	x = 1;
	while (!(ft_strchr(stockage, '\n')) && x > 0)
	{
		x = read (fd, buffer, BUFFER_SIZE);
		if (x < 0)
			return (free(buffer), free(stockage), NULL);
		buffer[x] = '\0';
		if (!stockage)
			stockage = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(stockage, buffer);
			free (stockage);
			stockage = temp;
		}
	}
	return (free (buffer), stockage);
}

static char	*give_me_the_line(char *stockage)
{
	int	i;

	if (!stockage)
		return (NULL);
	i = 0;
	while (stockage[i] && stockage[i] != '\n')
		i++;
	if (stockage[i] == '\n')
		return (ft_substr (stockage, 0, i + 1));
	else
		return (ft_substr (stockage, 0, i));
}

static char	*save_mod(char *line)
{
	int	i;
	int	len;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	len = ft_strlen (line);
	if (line[i] == '\n')
		return (ft_substr(line, i + 1, len - (i + 1)));
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stockage;
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE >= 2147483647 || BUFFER_SIZE <= 0)
		return (NULL);
	stockage = fill_line_buffer (fd, stockage);
	line = give_me_the_line (stockage);
	temp = save_mod(stockage);
	free (stockage);
	stockage = temp;
	if (line && *line == '\0')
	{
		free (stockage);
		stockage = NULL;
		free (line);
		return (NULL);
	}
	return (line);
}
