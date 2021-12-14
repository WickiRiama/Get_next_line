/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:22:05 by mriant            #+#    #+#             */
/*   Updated: 2021/12/14 14:43:44 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	long int	ret;
	char		*buf;
	static char	*tail;
	char		*line;
	char		*endline;

	if (fd == -1 || BUFFER_SIZE == 0)
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = ft_strdup(tail);
	ret = BUFFER_SIZE;
	while (ret > 0 && !ft_strchr(buf, '\n'))
	{
		line = ft_strjoin(line, buf);
		ret = read (fd, buf, BUFFER_SIZE);
	}
	if (ret <= 0 && !tail)
	{
		free(buf);
		free(line);
		return (NULL);
	}
	endline = ft_strchr(buf, '\n');
	if (endline)
	{
		free(tail);
		tail = ft_substr(buf, 0, endline - buf + 1);
		line = ft_strjoin(line, tail);
		free(tail);
		tail = ft_strdup(endline + 1);
	}
	else
	{
		line = ft_strjoin(line, buf);
		free(tail);
		tail = NULL;
	}
	free(buf);
	return (line);
}

int main()
{
	int		fd;

	fd = open("test_file", O_RDONLY);

	char	*str = get_next_line(fd);

	printf("%s", str);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free (str);
	}
	close (fd);
}

