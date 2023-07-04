/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:58:11 by msakurad          #+#    #+#             */
/*   Updated: 2023/07/04 02:45:03 by msakurad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	storage_to_current_line(char **s1, char *s2)
{
	char	*tmp;

	if (!s1 && !s2)
		tmp = ft_strdup("");
	else if (*s1 && !s2)
		tmp = ft_strdup(*s1);
	else if (!*s1 && s2)
		tmp = ft_strdup(s2);
	else
		tmp = ft_strjoin(*s1, s2);
	free(*s1);
	*s1 = tmp;
}

static int	scan_n_check_fd(int fd, char **line)
{
	ssize_t	bytes_read;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buf[bytes_read] = '\0';
		if (!line)
			*line = ft_strdup("");
		storage_to_current_line(line, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	printf("stored line %s\n", *line);
	return (bytes_read);
}

static char	*save_and_clear(char **line)
{
	char	*next_line;
	char	*tmp;
	char	*pos_new_line;

	pos_new_line = ft_strchr(*line, '\n');
	if (pos_new_line)
	{
		next_line = ft_substr(*line, 0, pos_new_line - *line + 1);
		tmp = ft_strdup(pos_new_line + 1);
		free(*line);
		*line = tmp;
		if (!**line)
		{
			free(*line);
			*line = NULL;
		}
		return (next_line);
	}
	next_line = ft_strdup(*line);
	free(*line);
	*line = NULL;
	return (next_line);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	*bckup_line[1024];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 1024)
		return (NULL);
	bytes_read = scan_n_check_fd(fd, &bckup_line[fd]);
	printf("bckupline %s\n", bckup_line[fd]);
	if (bytes_read < 0 || (!bytes_read && !bckup_line[fd]))
		return (NULL);
	next_line = save_and_clear(&bckup_line[fd]);
	printf("bckupline %s\n", bckup_line[fd]);
	return (next_line);
}
