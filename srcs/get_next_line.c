/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:58:11 by msakurad          #+#    #+#             */
/*   Updated: 2023/06/06 16:36:31 by msakurad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	ssize_t	bytes_read;
	static ssize_t	total_bytes_read;
	char	*the_line;
	// char	*next_char;

	the_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	strcpy(the_line, "");
	bytes_read = read(fd, the_line, BUFFER_SIZE);
	total_bytes_read += bytes_read;
	printf("\nbytes read: %ld total: %ld\n", bytes_read, total_bytes_read);
	if (bytes_read <= 0)
		return (NULL);
	// while (1)
	// {
	// 	bytes_read = read(fd, next_char, 1); //BUFFER_SIZE);
	// 	if (bytes_read <= 0)
	// 		return (NULL);
	// 	if (next_char == '\n')
	// 		break ;
	// }
	return (the_line);
}
