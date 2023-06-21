/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:58:54 by msakurad          #+#    #+#             */
/*   Updated: 2023/06/20 22:38:10 by msakurad         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_joined;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s_joined = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (s_joined == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < s1_len)
	{
		s_joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && j < s2_len)
	{
		s_joined[i] = s2[j];
		i++;
		j++;
	}
	s_joined[i] = '\0';
	return (s_joined);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		s_len;
	int		i;

	s_len = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * (s_len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < s_len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((size_t)start > s_len)
		return (ft_strdup(""));
	if ((s_len - (size_t)start) < len)
		len = s_len - (size_t)start;
	sub_s = (char *)malloc(sizeof(char) * (len + 1));
	if (sub_s == NULL)
		return (NULL);
	ft_strlcpy(sub_s, &s[start], len + 1);
	return (sub_s);
}

// char	*next_str(int fd, int buf_size)
// {
// 	char	next_s[__INT_MAX__];
// 	char	*next_chr;
// 	int		count;
// 	ssize_t	bytes_read;

// 	count = 0;
// 	next_chr = (char *)malloc(sizeof(char) * 2);
// 	while (count < buf_size)
// 	{
// 		bytes_read = read(fd, next_chr, 1);
// 		if (bytes_read < 0)
// 		{
// 			free(next_chr);
// 			return (NULL);
// 		}
// 		if (next_s)
// 	}
// 	free(next_chr);
// 	return (next_s);
// }

// // char	*str_oneline_atatime(int fd)
// // {
// // 	ssize_t	bytesRead;
// // 	char		*strRead;

// // 	strRead = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// // 	bytesRead = read(fd, strRead, BUFFER_SIZE);
// // 	if (bytesRead <= 0)
// // 		return (NULL);
// // }
// // int	count_chrofline(int fd)