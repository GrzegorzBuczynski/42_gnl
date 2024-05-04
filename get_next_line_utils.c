/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:09:08 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/05/04 15:56:33 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *buffer, int c)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	if (c == '\0')
		return (buffer + ft_strlen(buffer));
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (&buffer[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *buff, char *temp)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!temp)
		return (0);
	if (!buff)
	{
		buff = malloc(sizeof(char));
		buff[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(temp) + 1));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (buff && buff[++i] != '\0')
		str[i] = buff[i];
	while (temp && temp[j] != '\0')
		str[i++] = temp[j++];
	str[i] = '\0';
	free(buff);
	return (str);
}
