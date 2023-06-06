/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:58:54 by msakurad          #+#    #+#             */
/*   Updated: 2023/06/06 17:05:03 by msakurad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*next_str(int fd, int buf_size)
{
	char	next_s[__INT_MAX__];
	char	*next_chr;
	int		count;
	ssize_t	bytes_read;

	count = 0;
	next_chr = (char *)malloc(sizeof(char) * 2);
	while (count < buf_size)
	{
		bytes_read = read(fd, next_chr, 1);
		if (bytes_read < 0)
		{
			free(next_chr);
			return (NULL);
		}
		if (next_s)
	}
	free(next_chr);
	return (next_s);
}

// char	*str_oneline_atatime(int fd)
// {
// 	ssize_t	bytesRead;
// 	char		*strRead;

// 	strRead = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	bytesRead = read(fd, strRead, BUFFER_SIZE);
// 	if (bytesRead <= 0)
// 		return (NULL);
// }
// int	count_chrofline(int fd)