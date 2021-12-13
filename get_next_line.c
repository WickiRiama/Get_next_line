/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:22:05 by mriant            #+#    #+#             */
/*   Updated: 2021/12/10 11:43:04 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //NULL malloc free
#include <sys/types.h> // open read
#include <sys/uio.h> // read
#include <unistd.h> // read
#include <stdio.h> // printf
#include <sys/stat.h> // open
#include <fcntl.h> // open

char	*get_next_line(int fd)
{
	int			ret;
	char		*buf;
	static char	*str;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	str = NULL;
	if (fd == -1)
		return (NULL);
	while (ret)
	{
		ret = read (fd, buf, BUFFER_SIZE);
		// si ret = -1, supprimer tout
		str = ft_strjoin(str, buf);
	}
	buf[ret] = '\0';
	return (buf);
}

int main()
{
	char	*str;
	int		fd;

	fd = open("test_file", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	close (fd);
}
