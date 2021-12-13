/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:22:05 by mriant            #+#    #+#             */
/*   Updated: 2021/12/13 15:09:04 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			ret;
	char		*buf;
	static char	*tail;
	char		*line;
	char		*endline;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = tail;
	ret = BUFFER_SIZE;
	if (fd == -1 || BUFFER_SIZE == 0)
		return (NULL);
	while (ret && !ft_strchr(buf, '\n'))
	{
		line = ft_strjoin(line, buf);
		ret = read (fd, buf, BUFFER_SIZE);
		// si ret = -1, supprimer tout
	}
	if (!ret && !tail)
		return (NULL);
	endline = ft_strchr(buf, '\n');
	if (endline)
	{
		line = ft_strjoin(line, ft_substr(buf, 0, endline - buf + 1));
		tail = endline + 1;
	}
	else
	{
		line = ft_strjoin(line, buf);
		tail = NULL;
	}
	return (line);
}

int main()
{
	char	*str;
	int		fd;

	fd = open("test_file", O_RDONLY);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
	close (fd);
}
