/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:58:11 by msakurad          #+#    #+#             */
/*   Updated: 2023/06/04 00:02:46 by msakurad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static ssize_t	bytesRead;
	static char		*strRead;

	strRead = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytesRead = read(fd, strRead, BUFFER_SIZE);
	if (bytesRead <= 0)
		return (NULL);
	return (strRead);
}
