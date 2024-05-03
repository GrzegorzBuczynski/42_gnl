/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:50:09 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/05/03 18:52:33 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_to_buffer(char *buffer, int fd)
{
	int	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes] = '\0';
	return (bytes);
}

char	*load_to_line(char *line, char *buffer)
{
	char	*str;
	int		j;

	j = 0;
	if (!buffer[0])
		return (0);
	while (buffer[j] && buffer[j] != '\n')
		j++;
	if (buffer[j] == '\n')
		j++;
	str = malloc(sizeof(char) * (ft_strlen(line) + j + 1));
	if (!str)
		return (0);
	str[0] = '\0';
	if (line)
		ft_strlcat(str, line, (ft_strlen(line) + 1));
	if (line)
		free(line);
	ft_strlcat(str, buffer, (ft_strlen(str) + j + 1));
	ft_memmove(buffer, (buffer + j), j);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	line = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	while (!ft_strchr(line, '\n'))
	{
		bytes = ft_strlen(buffer);
		if (bytes == 0)
			bytes = read_to_buffer(buffer, fd);
		if (!bytes && line)
			return (line);
		if (!bytes)
			return (0);
		if (bytes > 0)
			line = load_to_line(line, buffer);
		if (bytes == -1)
			return (0);
	}
	return (line);
}

// int	main(void)
// {
// 	char *str4 = 0;
// 	int fd = open("41_no_nl", O_RDONLY);
// 	for (int a = 0; a < 10; a++)
// 	{
// 		str4 = get_next_line(fd);
// 		if (str4 == NULL)
// 		{
// 			printf("	NULL	\n");
// 			break ;
// 		}
// 		printf("%s", str4);
// 		free(str4);
// 	}
// 	// printf("\n");
// 	// printf("\n");
// 	// str4 = get_next_line(fd);
// 	// str4 = get_next_line(fd);
// 	// free(str4);
// 	// str4 = get_next_line(fd);
// 	// free(str4);
// 	// str4 = get_next_line(fd);
// 	// free(str4);
// 	// str4 = get_next_line(fd);
// 	// free(str4);
// 	// str4 = get_next_line(fd);
// 	// free(str4);

// 	close(fd);
// }