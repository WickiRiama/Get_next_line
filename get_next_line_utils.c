/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:32:44 by mriant            #+#    #+#             */
/*   Updated: 2021/12/13 12:36:41 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i ++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i ++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = malloc(count * size);
	if (!result)
		return (NULL);
	ft_bzero(result, count * size);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
			return ((char *)s + i);
		i ++;
	}
	if (str[i] == (unsigned char) c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char const *s, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	result = ft_calloc(sizeof(char), (ft_strlen(s) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (s && s[i])
	{
		result[i] = s[i];
		i ++;
	}
	while (s2 && s2[j])
	{
		result[i] = s2[j];
		i ++;
		j ++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s || start > ft_strlen(s))
	{
		result = ft_calloc(1, 1);
		return (result);
	}
	if (ft_strlen(s) - start < len)
		i = ft_strlen(s) - start;
	else
		i = len;
	result = ft_calloc(sizeof(char), (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		result[i] = s[i + start];
		i ++;
	}
	return (result);
}
