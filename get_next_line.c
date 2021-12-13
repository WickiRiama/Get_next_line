/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:22:05 by mriant            #+#    #+#             */
/*   Updated: 2021/12/13 12:36:38 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			ret;
	char		*buf;
	static char	*tail;
	char		*line;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = tail;
	ret = BUFFER_SIZE;
	if (fd == -1)
		return (NULL);
	while (ret && !ft_strchr(buf, '\n'))
	{
		line = ft_strjoin(line, buf);
		ft_bzero(buf, BUFFER_SIZE + 1);
		ret = read (fd, buf, BUFFER_SIZE);
		// si ret = -1, supprimer tout
	}
	line = ft_strjoin(line, ft_substr(buf, 0, (ft_strchr(buf, '\n') - buf + 1)));
	tail = ft_strchr(buf, '\n') + 1;
	return (line);
}

int main()
{
	char	*str;
	int		fd;

	fd = open("test_file", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	close (fd);
}
