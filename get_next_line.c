/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuczyns <gbuczyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:50:09 by gbuczyns          #+#    #+#             */
/*   Updated: 2024/05/02 15:17:39 by gbuczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_buffer(char *buffer, int fd)
{
	char	*temp;
	int		bytes;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			return (0);
		}
		temp[bytes] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*load_to_line(char *buffer)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] != '\n')
		i++;
	i++;
	str = malloc(sizeof(char) * i);
	if (!str)
		return (0);
	str[i] = '\0';
	while (--i + 1)
		str[i] = buffer[i];
	return (str);
}

char	*update_buffer(char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!str)
		return (0);
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = read_to_buffer(buffer, fd);
	line = load_to_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}

// int	main(void)
// {
// 	// char *str = 0;
// 	// char *str2 = 0;
// 	// char *str = "123456";
// 	// char *str2 = "qwert";
// 	// char *str3;
// 	// printf("lenght %d\n", ft_strlen(str));
// 	// printf("pos3 = %p\n", ft_strchr(str, '3'));
// 	// printf("pos4 = %p\n", ft_strchr(str, '4'));
// 	// //	printf("getreturn (= %p\n", get_next_line(4));
// 	// str3 = ft_strjoin(str, str2);
// 	// if (str3 != NULL)
// 	// {
// 	// 	printf("strjoin %s", str3);
// 	// }
// 	// else
// 	// {
// 	// 	printf("strjoin failed\n");
// 	// }
// 	char *str4 = 0;
// 	int fd = open("tekst.txt", O_RDONLY);
// 	str4 = get_next_line(fd);
// 	// if (str4)
// 	// 	printf("%s", str4);
// 	free(str4);
// 	str4 = get_next_line(fd);
// 	free(str4);
// 		str4 = get_next_line(fd);
// 	free(str4);
// 		str4 = get_next_line(fd);
// 	free(str4);
// 		str4 = get_next_line(fd);
// 	free(str4);
// 		str4 = get_next_line(fd);
// 	free(str4);
// 			str4 = get_next_line(fd);
// 	free(str4);
// 	// if (str4)
// 	// 	printf("%s", str4);
// 	close(fd);
// }