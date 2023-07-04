/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_full.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:58:11 by msakurad          #+#    #+#             */
/*   Updated: 2023/07/03 16:01:01 by msakurad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	char		*buf;
	char		*the_line;
	static char	*next_line;
	char		*p_new_line;
	char		*stored_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// printf("check point 1\n");
	if (!buf)
		return (NULL);
	if (!next_line)
		stored_line = ft_strdup("");
	else
		stored_line = ft_strdup(next_line);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		// printf("check point 2: buf \"%s\"\n", buf);
		buf[bytes_read] = '\0';
		if (!next_line)
			next_line = ft_strdup("");
		free(stored_line);
		if (!next_line && !buf)
			stored_line = ft_strdup("");
		else if (!next_line)
			stored_line = ft_strdup(buf);
		else if (!buf)
			stored_line = ft_strdup(next_line);
		else
			stored_line = ft_strjoin(next_line, buf);
		free(next_line);
		next_line = ft_strdup(stored_line);
		// printf("check point 3: stored_line \"%s\"\n", stored_line);
		if (ft_strchr(buf, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		// printf("check point 4\n");
	}
	free(buf);
	buf = NULL;
	// printf("check point 5\n");
	p_new_line = ft_strchr(stored_line, '\n');
	if (p_new_line)
	{
		// printf("check point 6: p_new_linestr \"%ld\"\n", p_new_line - stored_line);
		the_line = ft_substr(stored_line, 0, p_new_line - stored_line + 1);
		// printf("check point 7: the_line \"%s\"\n", the_line);
		free(next_line);
		next_line = NULL;
		next_line = ft_strdup(p_new_line + 1);
		// printf("check point 8: next_line \"%s\"\n", next_line);
	}
	/* quando o read termina de varrer o fd */
	else
	{
		the_line = ft_strdup(stored_line);

		/* final command before the gnl function ends */
		if (!bytes_read && (!next_line || !*stored_line))
		{
			free(stored_line);
			free(the_line);
			return (NULL);
		}
		free(next_line);
		next_line = NULL;
	}
	// printf("check point 9: the_line \"%s\"\n", the_line);
	free(stored_line);
	if (bytes_read < 0) 
		return (NULL);
	return (the_line);
}
