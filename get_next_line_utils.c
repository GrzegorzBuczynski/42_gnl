/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:09:08 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/04/21 14:53:06 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *line, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!buffer)
		return (0);
	if (!line)
	{
		line = (char *)malloc(1 * sizeof(char));
		line[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(line) + ft_strlen(buffer)) + 1));
	if (str == 0)
		return (0);
	i = -1;
	j = 0;
	if (line)
		while (line[++i] != '\0')
			str[i] = line[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(line) + ft_strlen(buffer)] = '\0';
	free(line);
	return (str);
}
