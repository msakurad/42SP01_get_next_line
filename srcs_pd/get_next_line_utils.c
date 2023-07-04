/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pd_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakurad <msakurad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:58:54 by msakurad          #+#    #+#             */
/*   Updated: 2023/07/03 16:15:20 by msakurad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str_join;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_join = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (str_join == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		ft_strlcpy(str_join, s1, s1_len + 1);
		free(s1);
	}
	ft_strlcpy(str_join + s1_len, s2, s2_len + 1);
	return (str_join);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, char c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
