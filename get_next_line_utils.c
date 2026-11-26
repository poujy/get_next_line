/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquer <jquer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 09:33:19 by username          #+#    #+#             */
/*   Updated: 2026/11/26 09:55:43 by jquer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(const char *str, int ch)
{
	while (*str && *str != (char) ch)
	{
		str++;
		if (*str == (char) ch)
			return ((char *) str);
	}
	if (*str == (char) ch)
		return ((char *) str);
	return (NULL);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*res;

	n = 0;
	if (!s)
		return (NULL);
	if (start > gnl_strlen(s))
		len = 0;
	if ((gnl_strlen(s) - start) < len)
		len = gnl_strlen(s) - start;
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (n < len)
	{
		res[n] = s[start];
		start++;
		n++;
	}
	res[n] = '\0';
	return (res);
}

size_t	gnl_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	while (dest_len < destsize && dest[dest_len])
		dest_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (destsize == 0 || destsize <= dest_len)
		return (destsize + src_len);
	i = 0;
	while (src[i] && dest_len + i < destsize - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	a;
	size_t	b;
	char	*res;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	res = malloc((a + b) + 1);
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	gnl_strlcat(res, s1, a + b + 1);
	gnl_strlcat(res, s2, a + b + 1);
	return (res);
}
