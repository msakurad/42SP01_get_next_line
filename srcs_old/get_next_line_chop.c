/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_chop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:58:11 by msakurad          #+#    #+#             */
/*   Updated: 2023/07/03 22:50:05 by msakurad         ###   ########.fr       */
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
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = 0;
		if (!line)
			*line = ft_strdup("");
		storage_to_current_line(line, buf);
		if (ft_strchr(buf, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (bytes_read);
}

static char	*save_and_clear(char **line)
{
	char	*out;
	char	*tmp;
	char	*nl;

	nl = ft_strchr(*line, '\n');
	if (nl)
	{
		out = ft_substr(*line, 0, nl - *line + 1);
		tmp = ft_strdup(nl + 1);
		free(*line);
		*line = tmp;
		if (!**line)
		{
			free(*line);
			*line = NULL;
		}
		return (out);
	}
	out = ft_strdup(*line);
	free(*line);
	*line = NULL;
	return (out);
}

char	*get_next_line(int fd)
{
	static char	*bckup_line;
	char		*next_line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bytes_read = scan_n_check_fd(fd, &bckup_line);
	if (bytes_read < 0)
		return (NULL);
	if (!bytes_read && !bckup_line)
		return (NULL);
	next_line = save_and_clear(&bckup_line);
	return (next_line);
}
