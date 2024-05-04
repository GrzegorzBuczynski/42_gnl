/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:33:22 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/04/27 15:58:46 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*load_to_buffer(int fd, char *buffer)
{
	char	*tmp_buffer;
	int		bytes;

	tmp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_buffer)
		return (0);
	bytes = 1;
	while (bytes != 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, tmp_buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp_buffer);
			return (0);
		}
		tmp_buffer[bytes] = '\0';
		buffer = ft_strjoin(buffer, tmp_buffer);
	}
	free(tmp_buffer);
	return (buffer);
}

char	*load_to_line(char *buffer)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (!buffer[0])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*update_buffer(char *buffer)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	temp = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!temp)
		return (0);
	i++;
	j = 0;
	while (buffer[i])
		temp[j++] = buffer[i++];
	temp[j] = '\0';
	free(buffer);
	return (temp);
}

ft_strjoin(buffer, temp_buffer)
{
	if(!temp_buffer)
		return(0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = load_to_buffer(fd, buffer);
	if (!buffer)
		return (0);
	line = load_to_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}
