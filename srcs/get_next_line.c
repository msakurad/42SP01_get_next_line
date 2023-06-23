/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:58:11 by msakurad          #+#    #+#             */
/*   Updated: 2023/06/22 20:06:24 by msakurad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

char* get_next_line(int file_descriptor) {
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;
    size_t line_length = 0;
    ssize_t total_bytes_read = 0;

    bytes_read = read(file_descriptor, buffer + total_bytes_read, 1);
    while (total_bytes_read < BUFFER_SIZE - 1 && (bytes_read) > 0) {
        if (buffer[total_bytes_read] == '\n') {
            buffer[total_bytes_read] = '\0';
            line_length = total_bytes_read;
            break;
        }
        total_bytes_read++;
        bytes_read = read(file_descriptor, buffer + total_bytes_read, 1);

    }

    if (bytes_read == -1) {
        perror("Error reading file");
        return NULL;
    }

    if (line_length > 0) {
        char* line = (char*) malloc((line_length + 1) * sizeof(char));
        if (line == NULL) {
            perror("Memory allocation error");
            return NULL;
        }
        snprintf(line, line_length + 1, "%s", buffer);
        return line;
    }

    return NULL;
}



// char	*get_next_line(int fd)
// {
// 	ssize_t	bytes_read;
// 	char	*buf;
// 	char	*str;

// 	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	bytes_read = read(fd, buf, BUFFER_SIZE);
// 	if (bytes_read < 1)
// 		return (NULL);
// 	str = ft_strdup(buf);
// 	free(buf);
// 	// buf = NULL;
// 	return (str);
// }

// char	*get_next_line(int fd)
// {
// 	ssize_t		bytes_read;
// 	char		*buf;
// 	char		*the_line;
// 	static char	*next_line;
// 	char		*p_new_line;
// 	char		*stored_line;

// 	if (fd < 0 || BUFFER_SIZE < 1)
// 		return (NULL);
// 	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	printf("check point 1\n");
// 	stored_line = ft_strdup("");
// 	bytes_read = read(fd, buf, BUFFER_SIZE);
// 	while (bytes_read > 0)
// 	{
// 		printf("check point 2: buf \"%s\"\n", buf);
// 		if (!next_line)
// 			next_line = ft_strdup("");
// 		free(stored_line);
// 		stored_line = ft_strjoin(next_line, buf);
// 		free(next_line);
// 		next_line = ft_strdup(stored_line);
// 		printf("check point 3: stored_line \"%s\"\n", stored_line);
// 		if (ft_strchr(buf, '\n'))
// 			break ;
// 		bytes_read = read(fd, buf, BUFFER_SIZE);
// 		printf("check point 4\n");
// 	}
// 	free(buf);
// 	buf = NULL;
// 	printf("check point 5\n");
// 	p_new_line = ft_strchr(stored_line, '\n');
// 	if (p_new_line)
// 	{
// 		printf("check point 6: p_new_linestr \"%ld\"\n", p_new_line - stored_line);
// 		the_line = ft_substr(stored_line, 0, p_new_line - stored_line + 1);
// 		printf("check point 7: the_line \"%s\"\n", the_line);
// 		free(next_line);
// 		next_line = NULL;
// 		next_line = ft_strdup(p_new_line + 1);
// 		printf("check point 8: next_line \"%s\"\n", next_line);
// 	}
// 	else
// 	{
// 		the_line = ft_strdup(stored_line);
// 		if (!bytes_read && !next_line)
// 			return (NULL);
// 		free(next_line);
// 		next_line = NULL;
// 	}
// 	printf("check point 9: the_line \"%s\"\n", the_line);
// 	free(stored_line);
// 	if (bytes_read < 0)
// 		return (NULL);
// 	return (the_line);
// }
