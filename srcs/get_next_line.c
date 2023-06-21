/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:58:11 by msakurad          #+#    #+#             */
/*   Updated: 2023/06/21 17:31:15 by msakurad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	char		*buf;
	char		*the_line;
	static char	*next_line;
	char		*p_new_line;
	char		*recycle_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (!the_line)
			the_line = ft_strdup("");
		recycle_line = ft_strdup(the_line);
		the_line = ft_strjoin(recycle_line, buf);
		free(recycle_line);
		p_new_line = ft_strchr(buf, '\n');
		if (p_new_line)
			break ;
	}
	free(buf);
	if (bytes_read < 0 || (!bytes_read && !the_line))
		return (NULL);
	/* em desenvolvimento */
	if (p_new_line)
	{
		recycle_line = ft_substr(buf, 0, p_new_line - *line - 1);
	}
	return (the_line);
}
