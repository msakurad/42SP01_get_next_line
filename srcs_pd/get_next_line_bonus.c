/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:58:11 by msakurad          #+#    #+#             */
/*   Updated: 2023/07/03 16:57:25 by msakurad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*memory;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	memory = read_line_break(fd, memory);
	if (memory == NULL)
		return (NULL);
	line = get_whole_line(memory);
	memory = clear_memory(memory);
	return (line);
}

char	*read_line_break(int fd, char *memory)
{
	char	*buffer;
	ssize_t	read_bytes;

	if (ft_strchr(memory, '\n') != NULL)
		return (memory);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_bytes = 1;
	while (ft_strchr(memory, '\n') == NULL && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		memory = ft_strjoin(memory, buffer);
	}
	free(buffer);
	return (memory);
}

char	*get_whole_line(char *memory)
{
	int		i;
	char	*line;

	i = 0;
	if (memory[i] == '\0')
		return (NULL);
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		line = malloc((i + 2) * sizeof(char));
	else
		line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (memory[i] != '\0' && memory[i] != '\n')
	{
		line[i] = memory[i];
		i++;
	}
	if (memory[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*clear_memory(char *memory)
{
	int		i;
	int		j;
	char	*clean_memory;

	i = 0;
	if (memory == NULL)
		return (NULL);
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\0')
	{
		free(memory);
		return (NULL);
	}
	i++;
	clean_memory = malloc((ft_strlen(memory) - i + 1) * sizeof(char));
	j = 0;
	while (memory[i] != '\0')
		clean_memory[j++] = memory[i++];
	clean_memory[j] = '\0';
	free(memory);
	return (clean_memory);
}
