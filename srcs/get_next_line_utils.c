/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:58:54 by msakurad          #+#    #+#             */
/*   Updated: 2023/07/03 22:58:46 by msakurad         ###   ########.fr       */
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
	while (s1[i])
	{
		s_joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s_joined[i + j] = s2[j];
		j++;
	}
	s_joined[i + j] = '\0';
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
	while (s[i])
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
	size_t	i;

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
	i = 0;
	while (s[start + i] && i < len)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
