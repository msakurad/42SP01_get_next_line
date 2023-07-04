/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:59:28 by msakurad          #+#    #+#             */
/*   Updated: 2023/07/03 16:49:54 by msakurad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*clear_memory(char *memory);
char	*get_whole_line(char *memory);
char	*read_line_break(int fd, char *memory);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, char c);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif